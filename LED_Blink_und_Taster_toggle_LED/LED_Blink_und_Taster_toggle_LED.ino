/*  LED und Taster
    Tastendruck schaltet LED ein, nächster Tastendruck schaltet wieder aus --> TOGGELN, zusätzlich blinkt eine LED */
    
int ledPinBlink = 13;      // An Pin 13 wird die blinkende LED angeschlossen
                           // Name "ledPinBlink" vergeben, damit die SW besser lesbar ist
int ledPinTaster = 10;     // An Pin 10 wird die Taster LED angeschlossen                  
int tasterPin = 2;         // An Pin 2 wird der Taster angeschlossen
int tasterStatus;          // Variable zur Aufnahme des Tasterstatus
int tasterStatusOld;       // Variable zur Aufnahme des vorigen Tasterstatus 
int interval = 1000;       // Intervallzeit (1 Sek aus, 1 Sek an == 2 Sekunden)
unsigned long alteZeit;    // Zeit-Variable
int ledStatusBlink = LOW;  // Statusvariable für die Blink-LED
int ledStatusTaster = LOW; // Statusvariable für die Blink-LED

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
  
  // Taster Status abfragen
  tasterStatus = digitalRead(tasterPin);    // Fkt. liest den Zustand des digitalen Pins ein
  if ((tasterStatus == HIGH) && (tasterStatusOld == LOW)) // Taster mit "Pull-Down" --> HIGH dann ist Taster gedrückt 
  {                                                    // alter Zustand "LOW", aktueller Zustand "HIGH" -->  Flanke       
    ledStatusTaster = !ledStatusTaster;                // Toggeln Taster Status, "!" invert., LOW --> HIGH; HIGH --> LOW
    digitalWrite(ledPinTaster, ledStatusTaster);       // LED je nach Tasterstatus ein- od. ausschalten, d.h. "Toggeln" LED
  }
  tasterStatusOld = tasterStatus;                      // Aktueller tasterStatus speichern bevor wieder neu abgefragt wird
} // fkt loop
