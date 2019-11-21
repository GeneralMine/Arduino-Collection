//  Timer Interrupt-Steuerung mit der Bibliothek "TimerOne"
//  wird eine LED geblinkt. Parallel werden die ISR Aufrufe gezählt
//  und bei Änderung angezeigt, jedoch max alle "x" Sekunden

#include "TimerOne.h"                    // Einbinden der Bibliothek
#define  ANZEIGE_ZEIT 1000      

int ledpin = 7;                          // Pin für die Blink LED
long milliSek = 200;                     // Blinkintervall in mSek muss "long" sein
volatile int  ISRCounter = 0;            // zählt alle ISR Aufrufe
int ISRCounterOld = 0;                   // alten Zaehlerstand merken

void setup()
{
  Serial.begin(9600);                    // Serielle Schnittstelle öffnen 
  pinMode(ledpin, OUTPUT);       
  Timer1.initialize(milliSek*1000);      // Timer1 in MicroSek. einstellen
  Timer1.attachInterrupt(blinken);       // ISR Funktion zuordnen
}  // setup

void blinken()
{
  ISRCounter++;                          // Jeder ISR Aufruf wird gezaehlt 
  digitalWrite(ledpin, digitalRead(ledpin) ^ 1);  // Toggeln mit bitwise EXOR
}  // ISR

void loop()
{
  // Hier kann nun ganz normal euer Programm stehen
  // Die Led wird nun unabhaengig von eurem Programmcode
  // jede Sekunde einmal aufblinken. Hier wird z.B. nur alle "x" Sekunden
  // angezeigt wie oft die USR aufgerufen wurde
  
  if (ISRCounter != ISRCounterOld)       // ISR Zaehler geaendert ?
  {
    Serial.println(ISRCounter);          // Dann Zaehler anzeigen 
    ISRCounterOld = ISRCounter;          // Alter gleich aktueller Zaehlerstand
  }  // If
  delay(ANZEIGE_ZEIT);                   // Trotz Delay funktioniert Interrupt 
}  // loop
