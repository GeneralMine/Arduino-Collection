/*
 * The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 */
#include <LiquidCrystal.h>              //Bibliotheken eingefügt                  
#include <DHT.h>//Bibliotheken eingefügt
#define DHTPIN 1;                       //Der Daten Pin des DHTs wird auf 1 festgelegt
#define DHTTYPE DHT11                   //Der Typ des DHTs wird auf DHT11 eingestellt
#define LM35PIN 6;                      //Definition des LM35 Pins
#define DELAY 50;                       //Variable für kurze Wartezeit
DHT dht(DHTPIN,DHTTYPE);                //initialisierung der Bibliothek mit den Daten des Sensors
LiquidCrystal lcd(12,11,5,4,3,2);       //initialisierung der Bibliothek mit den Nummern der Pins des Displays
const int zyklen = 10;                  //Zyklen für sicheren Temperatur Wert
float feuchtigkeit;                     //Variable mit Kommastellen für die Luftfeuchtigkeit
float temperatur_LM35;                  //Variable mit Kommastellen für die Temperatur des LM35
float temperatur_DMH11;                 //Variable mit Kommastellen für die Temperatur des DHT11
void setup()          //Einmalige Befehle bei Programmstart für Einstellungen
{
  lcd.begin(20,4);    //Einstellung der Spalten und Zeilen
  dht.begin();        //start Befehl für Bibliothek
}

void loop()
{
  delay(1000);        //Warten auf Sensoren
  lese_temperatur();  //Funktionsaufruf zum Temperatur messen
  lese_feuchtigkeit();//Funktionsaufruf zum Feuchtigkeit messen 
}

void lese_temperatur()                      //Funktion zum Temperatur lesen
{
  for(int i = 0; i < zyklen; i++)           //Schleife für Mehrfache Wiederholung der Berechnung
  {                                         //Und für sicheren Temperaturwert
    int analogWert = analogRead(LM35PIN);   //lesen des analogen Wertes des LM35
    float temperatur_rechnen = (5 * 100 * analogWert) / 1024;     //Die Formel zur Berechnung
    resultTemp += zyklen;                   //Aufsummieren der Messwerte
    delay(DELAY);                           //Kurze Wartezeit
  }
  temperatur_LM35 /= zyklen;                //Berechnung des Mittelwerts
  temperatur_DHT11 = dht.readTemperature(); //Funktionsaufruf für den Temperaturwert des DHT11  
  lcd.setCursor(0,0);                       //Setze Cursor in die erste Zeile und Spalte (0 ist die 1ste)
  lcd.print("Temp-LM35: " + temperatur_LM35)  //Zeigt die Temperatur des LM35 an
  lcd.setCursor(0,1);                         //Cursor geht in die 2te Zeile
  lcd.print("Temp-DHT11: " + temperatur_DHT11); //Zeigt die Temperatur des DHT11 an
}

void lese_feuchtigkeit()                      //Funktion zum feuchtigkeit messen
{
  feuchtigkeit = dht.readHumidity();          //lese Feuchtigkeit vom DHT11
  lcd.setCursor(0,2);                         //setze Cursor in die 3te Zeile
  lcd.print("Feuchtigkeit: " + feuchtigkeit); //Zeige Feuchtigkeit an
}

