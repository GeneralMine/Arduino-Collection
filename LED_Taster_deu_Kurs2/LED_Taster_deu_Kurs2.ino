/*
  LED und Taster
  Schaltet eine LED ein solange ein Taster gedrückt ist 
 */
 
const int ledPin = 13;    // An Pin 13 wird die LED angeschlossen
                          // Name "ledPin" vergeben, damit die SW besser lesbar ist
const int tasterPin = 2;  // An Pin 2 wird der Taster angeschlossen
int tasterStatus;         // Variable zur Aufnahme des Tasterstatus

// die folgende "setup" routine muss einmal im Programm stehen und wird nach einem RESET einmal durchlaufen:
void setup()
{                
  pinMode(ledPin, OUTPUT);      // mit der Funktion "pinMode" wird der Pin "led" als Ausgang definiert
  pinMode(tasterPin, INPUT);    // "TasterPin"  als Eingang definieren
}

// die "loop" routine muss auch einmal im Programm stehen, wird aber immer wieder von vorne durchlaufen
// eine sogenannte Endlos-Schleife:
void loop()
{
  tasterStatus = digitalRead(tasterPin);  // Fkt. liest den Zustand des digitalen Pins ein
  if (tasterStatus == HIGH)               // PULL-DOWN  Variante
    digitalWrite(ledPin, HIGH);           // schaltet die LED ein (HIGH ist ein 5V Spannungs-Pegel)
  else
    digitalWrite(ledPin, LOW);            // schaltet die LED aus (LOW ist ein 0V Spannungs-Pegel)
}
/*
// Alternative (Programmierer sind schreibfaul !
void loop()
{   // gibt den Wert HIGH oder LOW aus, der eben eingelesen wurde
  digitalWrite(ledPin, digitalRead(tasterPin)); 
}
*/

