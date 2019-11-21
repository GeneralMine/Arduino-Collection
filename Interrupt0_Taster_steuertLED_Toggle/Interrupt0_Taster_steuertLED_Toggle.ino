/*   Taster per Interrupt lesen und LED toggeln lassen
Diese SW fumtioniert nur zuverlässig mit HW Entprellung! */

const int ledPin = 13;            // extra oder eingebaute LED
const int tasterPin = 2;          // Taster am int0
volatile byte ledStatus = 0;      // Led Status wird von ISR getoggelt
volatile int  ISRCounter = 0;     // zählt alle ISR Aufrufe
int ISRCounterOld = 0;            // alten Zaehlerstand merken

void setup()
{
  Serial.begin(9600);             // Serielle Schnittstelle öffnen 
  pinMode(ledPin, OUTPUT);        // LED Pin daher OUTPUT
  attachInterrupt(0, ISRledToggeln, RISING); // Interrupt=0, ISR-Name,
}  // setup                         Interrupt bei steigender Flanke 

void loop()
{
  //  beliebiger komplexter Code
  if (ISRCounter != ISRCounterOld) // ISR Zaehler geaendert ?
  {
    Serial.println(ISRCounter);    // Dann Zaehler anzeigen 
    ISRCounterOld = ISRCounter;    // Alter gleich aktueller Zaehlerstand
  }  // If
}  // loop

void ISRledToggeln()              // die Interrupt Fkt ISR
{ // Immer wenn die Taste gedrückt wird, wird diese Fkt aufgerufen 
  ISRCounter++;                   // Jeder ISR Aufruf wird gezaehlt 
  digitalWrite(ledPin, ledStatus);   
  ledStatus = !ledStatus;         // Toggeln
} // fct ISR                         
