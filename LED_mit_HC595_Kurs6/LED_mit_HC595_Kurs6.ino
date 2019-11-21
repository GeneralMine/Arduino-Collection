/*
  LED Lauflicht mit HC595
  Schaltet eine Reihe von LEDs nach einem bestimmten Muster ein und aus
  und nutzt dabei ein Schieberegister HC595 

  Im Schaltkreis sind 8 LEDs mit einem Widerstand gegen Masse geschaltet
  und mit den Ausgängen des HC595 verbunden  
 */

int taktPin = 8;        // SH_CP (11) = Schieberegister Takteingang (Shiftregister Clock Input)
int speicherPin = 9;    // ST_CP (12) = Speicherregister Takteingang (Storageregister Clock Input)
int datenPin = 10;      // DS (14) = Serieller Eingang (Serial data Input)

void setup()
{
  pinMode(taktPin,OUTPUT);          // "taktPin" als Ausgang definieren
  pinMode(speicherPin,OUTPUT);      // "speicherPin" als Ausgang definieren
  pinMode(datenPin,OUTPUT);         // "datenPin" als Ausgang definieren 
  resetPins();                      // Alle Pins auf LOW setzen. Diese Funktion ist unten definiert
  digitalWrite(datenPin, HIGH);     // DS für spätere Übernahme durch SH_CP auf HIGH setzen
  delay(20);                        // kurze Verarbeitungs-Pause
  digitalWrite(taktPin, HIGH);      // SH_CP; --> DS-Pegel-Eingang in interne Speicherregister übertragen
  delay(20);                        // kurze Verarbeitungs-Pause
  digitalWrite(speicherPin, HIGH);  // ST_CP;  --> interner Speicherregisterinhalt an Ausgänge übertragen
  delay(20);                        // kurze Verarbeitungs-Pause
  resetPins();                      // Alle Pins wieder auf LOW setzen
}

void loop()
{
     //   leere Haupt-Schleife// 
}    // loop

void resetPins()        // Funktion setzt alle Pins auf LOW (Reset)
{
  digitalWrite(taktPin, LOW); 
  digitalWrite(speicherPin, LOW);
  digitalWrite(datenPin, LOW);
}  

