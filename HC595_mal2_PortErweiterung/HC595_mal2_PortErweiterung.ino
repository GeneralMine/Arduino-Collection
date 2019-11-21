/* Zwei kaskadierte HC595 also 16 Ausgänge. Der Überlauf des 1. HC595 wird an den Datenpin
des 2. HC595 angeschlossen.
Ausgegeben werden Muster und ein 16 Bit Zähler  */

int taktPin = 8;        // SH_CP (11) = Schieberegister Takteingang (Shiftregister Clock Input)
int speicherPin = 9;    // ST_CP (12) = Speicherregister Takteingang (Storageregister Clock Input)
int datenPin = 10;      // DS (14) = Serieller Eingang (Serial data Input)

void setup(){
  pinMode(taktPin,OUTPUT);          // "taktPin" als Ausgang definieren
  pinMode(speicherPin,OUTPUT);      // "speicherPin" als Ausgang definieren
  pinMode(datenPin,OUTPUT);         // "datenPin" als Ausgang definieren 
}  // setup

void loop(){
  sendeBytes(0B1111111111111111);       // Zu übertragene Binärzahl
  delay(1000);
  sendeBytes(0B0000000000000000);       // Zu übertragene Binärzahl
  delay(1000);
  sendeBytes(0B1010101010101010);       // Zu übertragene Binärzahl
  delay(1000);
  sendeBytes(0B0101010101010101);       // Zu übertragene Binärzahl
  delay(1000);
  for (int i=0; i<65535; i++)
  {
    sendeBytes(i);                      // eigene Fkt
    delay(100);
  }  // for
}  // loop

// Funktion zum Übertragen der beiden BYTES an den HC595
void sendeBytes(int wert)
{
  digitalWrite(speicherPin, LOW);                      // HC595 Pin ST_CP auf Low
  shiftOut(datenPin, taktPin, MSBFIRST, wert >> 8);    // High Byte 8 Bit nach rechts, dann ausgeben
  shiftOut(datenPin, taktPin, MSBFIRST, wert & 255);   // High Byte löschen und Low Byte ausgeben
  digitalWrite(speicherPin, HIGH);                     // Pin ST_CP auf HIGH (Flanke) --> Wert übernehmen& ausgeben
}  // fct

