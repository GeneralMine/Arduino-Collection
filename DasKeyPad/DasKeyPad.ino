/*
Scope:         Das KeyPad (Digital)
Date:          30.03.2013
Description:   Dieser Sketch zeigt Dir die Ansteuerung eines KeyPads (Digital)
               Die Anzeige des gedrückten Tasters erfolgt im Serial-Monitor
Referenz:      http://arduino.cc/en/Reference/Serial
               http://arduino.cc/en/Reference/If
*/

#define KEY_NOT_PRESSED '-'  // Wird benötigt, wenn keine Taste gedrückt wird

// int row[] = {2, 3, 4, 5};    // Array mit Zeilen Pin-Nummern initialisieren
// int col[] = {6, 7, 8, 9};    // Array mit Spalten Pin-Nummern initialisieren


void setup()
{
  Serial.begin(9600);               // Serielle Ausgabe vorbereiten
  setKeyPad();
}

void loop()
{
  char myKey = readKey();           // Abfragen des gedrückten Tasters
  if(myKey != KEY_NOT_PRESSED)      // Abfrage, ob irgendein Taster gedrückt
    Serial.println(myKey);          // Ausgabe des Tastenzeichens
}

