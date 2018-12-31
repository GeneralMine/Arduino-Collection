/* Programm steuert eine Wetterstation mit zwei DHT11, LM35 Sensor;  zeigt die Zeit an
alles auf LCD und Monitor, Speichert LM35 und DHT, BD löscht, BR liest file 
BP+Zahl erhöht BM+Zahl erniedrigt Zeit 
arbeitet nicht mit delay oder millis() sondern mit now()-intervall*/

#include <dht11.h>                // DHT11 Bibliothek einbinden  
#include <LiquidCrystal.h>        // LCD Bibliothek einbinden
#include <Time.h>                 // Time (Zeit)  Bibliothek einbinden 
#include <SD.h>
  
dht11 DHT1;                        // Object DHT1 erzeugen
dht11 DHT2;                        // Object DHT2 erzeugen
#define DHT11_1_PIN 2             // Pin für serielle Kommunikation
#define DHT11_2_PIN 9             // Pin für serielle Kommunikation

const int LCD_RS = 8;             // LCD RS Register Select Pin (4)
const int LCD_Enable = 7;         // LCD ENABLE Pin (6)
const int LCD_D4 = 6;             // LCD Data4 Pin (14)
const int LCD_D5 = 5;             // LCD Data5 Pin (13)
const int LCD_D6 = 4;             // LCD Data6 Pin (12)
const int LCD_D7 = 3;             // LCD Data7 Pin (11)
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by unix time_t as ten ascii digits
#define TIME_HEADER  'T'   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

#define sensorPin 0                  // Verbunden mit LM35 Ausgang
#define DELAY 50                     // kurze Wartezeit
#define MAXMODE 3
const int cycles = 10;               // Anzahl der Messungen

const int chipSelect = 10;
int sdCardOK = false;
char myFileName[] = "wetter2.txt";
File myFile;

unsigned long alteZeit;              // Zeit-Variable
unsigned long interval = 7;       // Intervallzeit (1 Sek aus, 1 Sek an == 2 Sekunden)
time_t prevDisplay = 0;
int lcdAnzMode = 0;
int feuchteProz = 0;
int tempGrad = 0;

 
void setup()
{
  Serial.begin(9600);                       // Seriellen Monitor öffnen 
  setSyncProvider(requestSync);             //set function to call when sync required
  Serial.println("--> Waiting for sync message !! (ca. T1401541019)");
  
  lcd.begin(16, 2);                // set up the LCD's number of columns and rows: 
  lcd.print("hello, world! TC!");      // Print a message to the LCD.

  Serial.println("DHT TEST PROGRAM ");      
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  sdCardOK = sdStart(chipSelect);
}  // fct "setup"
 
void loop()
{
  if(Serial.available()) 
  {
    if (Serial.peek() == 'B')
      decodeBefehl();
    else
    {
      if (Serial.peek() == 'T')
        processSyncMessage();
    }
  }  // if
  while(Serial.available())
  {  
    Serial.println(Serial.read()); 
  }
  delay(50);
  
  if((now() - prevDisplay) > interval)
  {
    prevDisplay = now();
    if(timeStatus()!= timeNotSet)
    {
      Serial.println(); 
      digitalClockDisplay();                  // Zeit Anzeige PC-Monitor
      LCDdigitalClockDisplay();               // Zeit Anzeige LCD 
      if (writeSD_TimeDate())                 // Zeit in File schreiben 
      {
        Serial.print("Writing Time to:  ");
        Serial.print(myFileName);
        Serial.println("  erfolgreich");
      }  //if
      else
      {
        Serial.print("Writing Time to:  ");
        Serial.print(myFileName);
        Serial.println("  nicht erfolgreich");
      }  // else    
    }  //if

    int chk1;                                  // empfängt Zeichen vom Sensor
    Serial.println("Type,\t\tstatus,\tHumidity (%),\tTemperature (C)");  // Überschrift ausgeben
    Serial.print("DHT11_1, \t");    
    chk1 = DHT1.read(DHT11_1_PIN);                // Read Sensor Data
    switch (chk1)                              // erstes Zeichen ist Sensor Status
    {
      case DHTLIB_OK:                         // Sensor ist OK  
                Serial.print("OK,\t"); 
                break;
      case DHTLIB_ERROR_CHECKSUM:             // Übertragungsfehler
                Serial.print("Checksum error,\t"); 
                break;
      case DHTLIB_ERROR_TIMEOUT:              // Time Out Error 
                Serial.print("Time out error,\t"); 
                break;
      default:                                // unbekannter Fehler 
                Serial.print("Unknown error,\t"); 
                break;
    }  // switch
    feuchteProz = DHT1.humidity;
    Serial.print(feuchteProz);             // Feuchte lesen mit eine Kommastelle und anzeigen
    Serial.print("\t\t");                    // TAB ausgeben 
    tempGrad = DHT1.temperature;
    Serial.println(tempGrad);        // Temp lesen mit eine Kommastelle und anzeigen

    if (writeSD_DHTData(1, feuchteProz, tempGrad))  // DHT Data  in SD File schreiben
    {
      Serial.print("Writing DHT Data to:  ");
      Serial.print(myFileName);
      Serial.println("  erfolgreich");
    }  //if
    else
    {
      Serial.print("Writing DHT Data to:  ");
      Serial.print(myFileName);
      Serial.println("  nicht erfolgreich");
    }  // else    

    int chk2;                                  // empfängt Zeichen vom Sensor
    Serial.print("DHT11_2, \t");    
    chk2 = DHT2.read(DHT11_2_PIN);                // Read Sensor Data
    switch (chk2)                              // erstes Zeichen ist Sensor Status
    {
      case DHTLIB_OK:                         // Sensor ist OK  
                Serial.print("OK,\t"); 
                break;
      case DHTLIB_ERROR_CHECKSUM:             // Übertragungsfehler
                Serial.print("Checksum error,\t"); 
                break;
      case DHTLIB_ERROR_TIMEOUT:              // Time Out Error 
                Serial.print("Time out error,\t"); 
                break;
      default:                                // unbekannter Fehler 
                Serial.print("Unknown error,\t"); 
                break;
    }  // switch

    feuchteProz = DHT2.humidity;
    Serial.print(feuchteProz);             // Feuchte lesen mit eine Kommastelle und anzeigen
    Serial.print("\t\t");                    // TAB ausgeben 
    tempGrad = DHT2.temperature;
    Serial.println(tempGrad);        // Temp lesen mit eine Kommastelle und anzeigen

    if (writeSD_DHTData(2, feuchteProz, tempGrad))  // DHT Data  in SD File schreiben
    {
      Serial.print("Writing DHT Data to:  ");
      Serial.print(myFileName);
      Serial.println("  erfolgreich");
    }  //if
    else
    {
      Serial.print("Writing DHT Data to:  ");
      Serial.print(myFileName);
      Serial.println("  nicht erfolgreich");
    }  // else    

    float resultTemp = 0.0;            // Variable für die berechnete Temperatur
    for(int i = 0; i < cycles; i++)    // mehrmals messen, damit Ergebnis stabiler
    {
      int analogValue = analogRead(sensorPin);        // Sensor einlesen und Analogwert speichern
      float temperature = (5.0 * 100.0 * analogValue) / 1024;  // Wert in eine Temperatur umwandeln
      resultTemp += temperature;                      // Aufsummieren der Messwerte
      delay(DELAY);
    } // for
    resultTemp /= cycles;              // Berechnung des Durchschnittes oder Mittelwerts  
    Serial.print("LM35 Temperatur:  ");     // Ausgabe an die serielle Schnittstelle
    Serial.print(resultTemp);          // Ausgabe an die serielle Schnittstelle
    Serial.write(0xB0);                // Ausgabe ASCII Grad Zeichen "°" direkt als HEX Wert
    Serial.println(" C");              // Ausgabe an die serielle Schnittstelle mit neue Zeile

    if (writeSD_LM35Temp(resultTemp))  // LM35 Temp in SD File schreiben
    {
      Serial.print("Writing LM35 Temp. to:  ");
      Serial.print(myFileName);
      Serial.println("  erfolgreich");
    }  //if
    else
    {
      Serial.print("Writing LM35 Temp. to:  ");
      Serial.print(myFileName);
      Serial.println("  nicht erfolgreich");
    }  // else    

    switch (lcdAnzMode)
    {
      case 0:
      {
        // set the cursor to column 0, line 1
        // (note: line 1 is the second row, since counting begins with 0):
        lcd.setCursor(0, 1);             // Cursor to column 0, line 1; 
        lcd.print("                    ");   // Zeile löschen
        lcd.setCursor(0, 1);             // Cursor to column 0, line 1; 
        lcd.print("DHT11_1: H=");               // print the number of seconds since reset:
        lcd.setCursor(9, 1);             // Cursor to column 0, line 1; 
        lcd.print(DHT1.humidity,1);       // print the number of seconds since reset:
        lcd.setCursor(11, 1);             // Cursor to column 0, line 1; 
        lcd.print(" T=");              // print the number of seconds since reset:
        lcd.setCursor(14, 1);             // Cursor to column 0, line 1; 
        lcd.print(DHT1.temperature,1);       // print the number of seconds since reset:
        // delay(3000);                              // alle 3 Sekunden anzeigen
        break;
      }  // case
      case 1:
      {
        // set the cursor to column 0, line 1
        // (note: line 1 is the second row, since counting begins with 0):
        lcd.setCursor(0, 1);             // Cursor to column 0, line 1; 
        lcd.print("                    ");   // Zeile löschen
        lcd.setCursor(0, 1);             // Cursor to column 0, line 1; 
        lcd.print("DHT11_2: H=");               // print the number of seconds since reset:
        lcd.setCursor(9, 1);             // Cursor to column 0, line 1; 
        lcd.print(DHT2.humidity,1);       // print the number of seconds since reset:
        lcd.setCursor(11, 1);             // Cursor to column 0, line 1; 
        lcd.print(" T=");              // print the number of seconds since reset:
        lcd.setCursor(14, 1);             // Cursor to column 0, line 1; 
        lcd.print(DHT2.temperature,1);       // print the number of seconds since reset:
        // delay(3000);                              // alle 3 Sekunden anzeigen
        break;
      }  // case
      case 2:
      {
        // set the cursor to column 0, line 1
        // (note: line 1 is the second row, since counting begins with 0):
        lcd.setCursor(0, 1);             // Cursor to column 0, line 1; 
        lcd.print("                    ");   // Zeile löschen
        lcd.setCursor(0, 1);             // Cursor to column 0, line 1; 
        lcd.print("LM35 Temp.=");               // print the number of seconds since reset:
        lcd.setCursor(11, 1);             // Cursor to column 0, line 1; 
        lcd.print(resultTemp);       // print the number of seconds since reset:
        // delay(3000);                              // alle X Sekunden anzeigen
        break;
      }  // case
      default:
        break;
    }  // switch
    if (lcdAnzMode < (MAXMODE - 1))
      lcdAnzMode++;
    else
      lcdAnzMode = 0;
  } // "if ((millis() - alteZeit) > interval)"
}   // fct "loop"

void digitalClockDisplay(){
  // digital clock display of the time
  printDigits(hour(), false);
  printDigits(minute(), true);
  printDigits(second(), true);
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.println(year()); 
}

void printDigits(int digits, int dPunkt){
  // utility function for digital clock display: prints preceding colon and leading 0
  if (dPunkt)
    Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
