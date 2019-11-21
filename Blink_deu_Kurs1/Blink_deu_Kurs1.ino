/*
  Blink
  Schaltet eine LED zyklisch ein und aus (blinken) 
 */
 
int ledPin = 13;    // An Pin 13 wird die LED angeschlossen
                    // Name "led" vergeben, damit die SW besser lesbar ist


// die folgende "setup" routine muss einmal im Programm stehen und wird nach einem RESET einmal durchlaufen:
void setup()
{                
  pinMode(ledPin, OUTPUT);        // mit der Funktion "pinMode" wird der Pin "led" als Ausgang definiert
}


// die "loop" routine muss auch einmal im Programm stehen, wird aber immer wieder von vorne durchlaufen
// eine sogenannte Endlos-Schleife:
void loop()
{
  digitalWrite(ledPin, HIGH);     // schaltet die LED ein (HIGH ist ein Spannungs-Pegel)
  delay(1000);                    // für 1000 ms also 1 sec warten
  digitalWrite(ledPin, LOW);      // schaltet die LED aus indem der Spannungs-Pegel auf LOW gesetzt wird
  delay(100);                     // für 600 ms also 0,6 sec warten
}


