/*   Taster per Interrupt lesen und LED toggeln lassen
Diese SW fumtioniert nur zuverlässig mit HW Entprellung! */

const int led1Pin = 13;           // extra oder eingebaute LED
const int led2Pin = 12;           // extra eingebaute LED
const int taster1Pin = 2;         // Taster am int0
const int taster2Pin = 3;         // Taster am int1
volatile byte led1Status = 0;     // Led Status wird von ISR getoggelt
volatile byte led2Status = 0;     // Led Status wird von ISR getoggelt
volatile int  ISR0Counter = 0;    // zählt alle ISR Aufrufe
volatile int  ISR1Counter = 0;    // zählt alle ISR Aufrufe
int ISR0CounterOld = 0;
int ISR1CounterOld = 0;

void setup()
{
  Serial.begin(9600);             // Serielle Schnittstelle öffnen 
  pinMode(led1Pin, OUTPUT);       // LED Pin daher OUTPUT
  pinMode(led2Pin, OUTPUT);       // LED Pin daher OUTPUT
  attachInterrupt(0, ISR0ledSchalten, RISING); // Interrupt=0, ISR-Name,
  attachInterrupt(1, ISR1ledSchalten, RISING); // Interrupt=1, ISR-Name,
}  // setup                         Interrupt bei steigender Flanke 

void loop()
{
  //  beliebiger komplexter Code
  if ((ISR0Counter != ISR0CounterOld)||(ISR1Counter != ISR1CounterOld)) // ISR Zaehler geaendert ?
  {
    Serial.print(ISR0Counter);    // Dann Zaehler anzeigen 
    Serial.print("   :   ");      
    Serial.println(ISR1Counter);  // Dann Zaehler anzeigen 
    ISR0CounterOld = ISR0Counter; // Alter gleich aktueller Zaehlerstand
    ISR1CounterOld = ISR1Counter; // Alter gleich aktueller Zaehlerstand
  }  // IF
}  // loop

void ISR0ledSchalten()             // die Interrupt Fkt ISR
{ // Immer wenn die Taste gedrückt wird, wird diese Fkt aufgerufen 
  ISR0Counter++;                   // Jeder ISR Aufruf wird gezaehlt 
  digitalWrite(led1Pin, led1Status);   
  led1Status = !led1Status;        // Toggeln
} // fct ISR                         

void ISR1ledSchalten()             // die Interrupt Fkt ISR
{ // Immer wenn die Taste gedrückt wird, wird diese Fkt aufgerufen 
  ISR1Counter++;                   // Jeder ISR Aufruf wird gezaehlt 
  digitalWrite(led2Pin, led2Status);   
  led2Status = !led2Status;        // Toggeln
} // fct ISR                         
