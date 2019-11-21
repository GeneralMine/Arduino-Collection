/*  LED Lauflicht mit HC595
    Schaltet eine Reihe von LEDs nach einem bestimmten Muster ein und aus
    und nutzt dabei ein Schieberegister HC595 
    Hier alle digitalen Werte von 0 bis 255 */

int taktPin = 8;        // SH_CP (11) = Schieberegister Takteingang (Shiftregister Clock Input)
int speicherPin = 9;    // ST_CP (12) = Speicherregister Takteingang (Storageregister Clock Input)
int datenPin = 10;      // DS (14) = Serieller Eingang (Serial data Input)
byte wert = 0;

void setup()
{
  pinMode(taktPin,OUTPUT);          // "taktPin" als Ausgang definieren
  pinMode(speicherPin,OUTPUT);      // "speicherPin" als Ausgang definieren
  pinMode(datenPin,OUTPUT);         // "datenPin" als Ausgang definieren 
  delay(10);                        // kurze Verarbeitungs-Pause
}

void loop()
{
  wert = 0;
  for (int i=0; i<256; i++)
  {
    digitalWrite(speicherPin, LOW);  // 
    delay(20);
    shiftOut(datenPin, taktPin, MSBFIRST, wert);
    digitalWrite(speicherPin, HIGH);  // ST_CP;  --> Speicherregisterinhalt an Ausgang
    wert++;                           // "wert" plus "1" 
    delay(300);
  }  // for
  delay(2000);
}    // loop

