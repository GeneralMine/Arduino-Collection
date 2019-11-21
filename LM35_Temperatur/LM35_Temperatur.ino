/*  Dieser Sketch zeigt Dir die Auswertung der Temperatur über
den Temperatursensor LM 35 und den seriellen Monitor  */

#define sensorPin 0                  // Verbunden mit LM35 Ausgang
#define DELAY 100                     // kurze Wartezeit
const int cycles = 20;               // Anzahl der Messungen

void setup()
{
  Serial.begin(9600);                // Die Schnittstelle auf 9600 Baud einstellen
}  // setup()

void loop()
{
  float resultTemp = 0.0;            // Variable für die berechnete Temperatur
  for(int i = 0; i < cycles; i++)    // mehrmals messen, damit Ergebnis stabiler
  {
    int analogValue = analogRead(sensorPin);        // Sensor einlesen und Analogwert speichern
    float temperature = (5.0 * 100.0 * analogValue) / 1024;  // Wert in eine Temperatur umwandeln
    resultTemp += temperature;                      // Aufsummieren der Messwerte
    delay(DELAY);
  } // for
  resultTemp /= cycles;              // Berechnung des Durchschnittes oder Mittelwerts  
  Serial.print("Temperatur:  ");     // Ausgabe an die serielle Schnittstelle
  Serial.print(resultTemp);          // Ausgabe an die serielle Schnittstelle
  Serial.write(0xB0);                // Ausgabe ASCII Grad Zeichen "°" direkt als HEX Wert
  Serial.println(" C");              // Ausgabe an die serielle Schnittstelle mit neue Zeile
} // loop()         
