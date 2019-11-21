/*  LED Lauflicht mit HC595
    Schaltet eine Reihe von LEDs mit 2 Mustern im Wechsel ein und aus
    Im Schaltkreis sind 8 LEDs mit einem Widerstand gegen Masse geschaltet
    und mit den Ausgängen des HC595 verbunden  */

int taktPin = 8;        // SH_CP (11) = Schieberegister Takteingang (Shiftregister Clock Input)
int speicherPin = 9;    // ST_CP (12) = Speicherregister Takteingang (Storageregister Clock Input)
int datenPin = 10;      // DS (14) = Serieller Eingang (Serial data Input)
int datenArray1[] = {1,0,1,0,1,0,1,0};  // Datenmuster 1
int datenArray2[] = {0,1,0,1,0,1,0,1};  // Datenmuster 2

void setup()
{
  pinMode(taktPin,OUTPUT);          // "taktPin" als Ausgang definieren
  pinMode(speicherPin,OUTPUT);      // "speicherPin" als Ausgang definieren
  pinMode(datenPin,OUTPUT);         // "datenPin" als Ausgang definieren 
  resetPins();                      // Alle Pins auf LOW setzen. Diese Funktion ist unten definiert
  delay(20);                        // kurze Verarbeitungs-Pause
}

void loop()
{
  setzePins(datenArray1);           // Setze Pins mit Fkt. über Daten-Array1
  digitalWrite(speicherPin, HIGH);  // ST_CP;  --> Speicherregisterinhalt an Ausgänge übertragen
  delay(800);
  setzePins(datenArray2);           // Setze Pins über Daten-Array2
  digitalWrite(speicherPin, HIGH);  // ST_CP;  --> Speicherregisterinhalt an Ausgänge übertragen
  delay(800);
}    // loop

void resetPins()        // Funktion setzt alle Pins auf LOW (Reset)
{
  digitalWrite(taktPin, LOW); 
  digitalWrite(speicherPin, LOW);
  digitalWrite(datenPin, LOW);
}  

void setzePins(int daten[])
{  // Fkt. schiebt alle 8 Bits aus dem Array nacheinander in das Schieberegister
  for(int i=0; i<8; i++)
  {
    resetPins();
    digitalWrite(datenPin, daten[i]);  // Datenelement[i] anlegen
    delay(20);
    digitalWrite(taktPin, HIGH);       // Daten ins Register schieben
    delay(20);
  }  // for
}    // fkt
