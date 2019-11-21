/*  LED und Taster
    Schaltet eine LED ein solange ein Taster gedrückt ist, zusätzlich blinkt eine LED  */
    
int ledPinBlink = 13;      // An Pin 13 wird die blinkende LED angeschlossen
                           // Name "ledPinBlink" vergeben, damit die SW besser lesbar ist
int ledPinTaster = 10;     // An Pin 10 wird die Taster LED angeschlossen                  
int tasterPin = 2;         // An Pin 2 wird der Taster angeschlossen
int tasterStatus;          // Variable zur Aufnahme des Tasterstatus
int interval = 1000;       // Intervallzeit (1 Sek aus, 1 Sek an == 2 Sekunden)
unsigned long alteZeit;    // Zeit-Variable
int ledStatus = LOW;       // Statusvariable für die Blink-LED

void setup()   // die "setup" Funktion muss einmal in jedem Programm stehen und wird beim Start einmal durchlaufen:
{                
  pinMode(ledPinBlink, OUTPUT);      // mit der Funktion "pinMode" wird der Pin "led" als Ausgang definiert
  pinMode(ledPinTaster, OUTPUT);     // mit der Funktion "pinMode" wird der Pin "led" als Ausgang definiert
  pinMode(tasterPin, INPUT);         // "TasterPin"  als Eingang definieren
  alteZeit = millis();                   // jetzigen Zeitstempel merken
}  // fkt setup

// die "loop" routine muss auch einmal im Programm stehen, wird aber immer wieder von vorne durchlaufen
// eine sogenannte Endlos-Schleife:
void loop()
{
  // Blink-LED über Intervallsteuerung blinken lassen
  if((millis() - alteZeit) > interval)
  {
    alteZeit = millis();
    ledStatus = !ledStatus;                 // Toggeln ledStatus, "!" invertiert, LOW --> HIGH; HIGH --> LOW
    digitalWrite(ledPinBlink, ledStatus);   // LED je nach ledStatus ein- od. ausschalten, d.h. "Toggeln" Blink LED 
  } // if 
  // Taster Status abfragen
  tasterStatus = digitalRead(tasterPin);    // Fkt. liest den Zustand des digitalen Pins ein
  if (tasterStatus == HIGH)                 // Taster mit "Pull-Down" -->  wenn HIGH dann ist Taster gedrückt 
    digitalWrite(ledPinTaster, HIGH);       // schaltet die LED ein (HIGH ist ein Spannungs-Pegel)
  else
    digitalWrite(ledPinTaster, LOW);        // schaltet die LED aus, der Spannungs-Pegel wird auf LOW gesetzt
} // fkt loop

