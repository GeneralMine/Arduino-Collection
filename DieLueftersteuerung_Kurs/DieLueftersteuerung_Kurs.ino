/* Description:   Dieser Sketch zeigt die Ansteuerung eines Lüfters, der 
über den Temperatursensor LM35 geregelt wird. Zudem werden Status-Informationen
im angeschlossenen LC-Display oder Monitor angezeigt.
Referenz:      http://www.arduino.cc/en/Reference/Wire
               http://www.arduino.cc/en/Reference/LiquidCrystal
               http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/Delay
               http://arduino.cc/en/Reference/If
               http://arduino.cc/en/Reference/Else       */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define sensorPin 0                  // Verbunden mit LM35 Ausgang
#define DELAY1 10                    // kurze Wartezeit beim Messen
#define DELAY2 1000                  // kurze Wartezeit beim Anzeigen
#define motorPin 9                   // Lüfter-Pin
#define threshold 25                 // Schalt-Temperatur für Lüfter (25 °C)
#define hysterese 1.0                // Hysterese-Wert (1.0 °C)
#define LCD FALSE                    // LCD vorhanden dann TRUE, sonst FASLE
const int cycles = 10;               // Anzahl der Messungen
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse auf 0x27 für 16 Zeichen/2 Zeilen

void setup()
{
  pinMode(motorPin, OUTPUT);         // Motor Pin als Ausgang definieren 
  #if (LCD)                          // bedingte Compilierung
    lcd.init();                      // LCD initialisieren
    lcd.backlight();                 // Hintergrundbeleuchtung aktivieren
  #else                              // bedingte Compilierung
    Serial.begin(9600);
  #endif                             // Ende der bedingte Compilierung
}  // setup()

void loop()
{
  float resultTemp = 0.0;                         // Float Variable für Temperaturberechnung
  for(int i = 0; i < cycles; i++)                 // Temperatur "cycles" mal messen 
  {
    int analogValue = analogRead(sensorPin);      // Sensor LM35 lesen 
    float temperature = (5.0 * 100.0 * analogValue) / 1024;  // Sensorwert in Temperaturwert wandeln
    resultTemp += temperature;                    // Aufsummieren der Messwerte
    delay(DELAY1);                                // kurze Messpause 
  }  // for
  resultTemp /= cycles;                           // Berechnung des Durchschnitts (Mittelwert)        

  #if (LCD)                    // bedingte Compilierung, Ausgabe an LCD
    lcd.clear();                                  // clear-Methode löscht LCD Inhalt
    lcd.print("Temp: ");                          // print-Methode schreibt LCD Inhalt
    lcd.print(resultTemp);
    lcd.write(0xB0);                              // Grad-Zeichen direkt als Hex-Wert
    lcd.print(" C");
    lcd.setCursor(0, 1);                          // setCorsor-Methode positioniert LCD-Cursor
    lcd.print("Motor: ");
  #else                        // bedingte Compilierung, Ausgabe an Monitor
    Serial.print("Temperatur: ");                 // print-Methode schreibt an Serial
    Serial.print(resultTemp);                     // Ausgabe abh. vom Typ der Variablen
    Serial.write(0xB0);                           // Ausgabe ASCII Grad Zeichen "°" direkt als HEX Wert
    Serial.println(" C");
    Serial.print("Motor: ");
  #endif  // Ende der bedingte Compilierung
  
  if(resultTemp > (threshold + hysterese))        // Temp. Wert größer Schwelle + Hysterese-Wert ? 
    digitalWrite(motorPin, HIGH);                 // erst dann einschalten
  else if(resultTemp < (threshold - hysterese))   // Temp. Wert kleiner Schwelle - Hysterese-Wert ?
    digitalWrite(motorPin, LOW);                  // erst dann ausschalten
  
  #if (LCD)                                       // bedingte Compilierung
    lcd.print(digitalRead(motorPin) == HIGH?"an":"aus");        // LCD vorhanden 
  #else
    Serial.println(digitalRead(motorPin) == HIGH?"an":"aus");   // Monitor 
  #endif                                          // Ende der bedingte Compilierung
  
  delay(DELAY2);                                  
}  // loop()
