/*  1) Tastenflanke (Änderung)  per HW Interrupt0 am Pin2 erkennen, dann Taster Status lesen 
und LED ein- bzw. ausschalten. 
2) Ferner eine LED am beliebigen Pin (hier Pin7) per "Timer Interrupt" blinken lassen.
Dazu wird die Library --> "TimerOne.h" verwendet.
Beide Funktionen laufen wegen Interrupts unabhängig vom Hauptprogramm "loop"
Ist bei zeitkritischen Funktionen wichtig bzw. wenn Hauptprgramm mit anderen Dingen beschäftigt ist */

#include "TimerOne.h"                              // Bibliothek einbinden

int ledPinBlinken = 7;                             // Pin für Blink LED per Timer Interrupt 
long milliSek = 200;                               // Blinkintervall muu "long" sein 

const int ledPinTaster = 13;                       // 13 ist auch eingebaute LED
const int tasterPin = 2;                           // Tasteränderung wird durch "int0" == Pin2 erkannt 

void setup()
{
  pinMode(ledPinBlinken, OUTPUT);                  // Pin als Ausgang setzen 
  Timer1.initialize(milliSek*1000);                // Blink Dauer einstellen, Wert in Micro Sekunden, daher * 1000
  Timer1.attachInterrupt(ISR_LEDblinken);          // ISR übergeben. Fkt wird autom. bei jedem Interrupt aufgerufen
  pinMode(ledPinTaster, OUTPUT);                   // Pin als Ausgang setzen 
  attachInterrupt(0, ISR_LEDschalten, CHANGE);     // Interrupt Nr, ISR und Flankenart übergeben. 
}  // setup

void ISR_LEDblinken()                                            // ISR für Timeer Interrupt
{
  digitalWrite(ledPinBlinken, digitalRead(ledPinBlinken) ^ 1);   // Toggeln der LED mit bitwise EXOR 
}  // ISR Timer Interrupt

void ISR_LEDschalten()                                     // ISR für HW Interrupt0 
{
  digitalWrite(ledPinTaster, digitalRead(tasterPin));      // Taster Status lesen, LED EIN- oder AUS schalten
}  // ISR Hardware Interrupt

void loop()                                       // beliebiger komplexter Code
{                                                 // Hier kann normal euer Programm stehen. Die Led wird
                                                  // nun unabhaengig von eurem "Loop Code" alle "x" Milli-Sek.
}  // loop                                        //  einmal aufblinken. Und der Taster steuert die 2. LED
