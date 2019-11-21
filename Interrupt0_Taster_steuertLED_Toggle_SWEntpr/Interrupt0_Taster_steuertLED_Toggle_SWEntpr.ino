/*   Taster per Interrupt lesen und LED toggeln lassen  */

#define BOUND 20                    // Entprell Zeit  
const int ledPin = 13;              // extra oder eingebaute LED
const int tasterPin = 2;            // Taster am int0
volatile byte ledStatus = 0;        // Led Status wird von ISR getoggelt

void setup()
{
  pinMode(ledPin, OUTPUT);          // LED Pin daher OUTPUT
  attachInterrupt(0, ISRledToggeln, RISING); // Interrupt=0, ISR-Name,
}  // setup                           Interrupt bei steigender Flanke 

void loop()
{
                                    //  beliebiger komplexter Code
}  // loop

void ISRledToggeln()                // die Interrupt Fkt ISR
{ // Immer wenn die Taste gedrückt wird, wird diese Fkt aufgerufen 
  for (int i=0;i<BOUND; i++)        // Schalter entprellen
  {                                 // indem kurz gewartet wird 
    for (int j=0;j<BOUND; j++);     // bis wieder eine Flanke  
  }                                 // zugelassen wird 
  digitalWrite(ledPin, ledStatus);   
  ledStatus = !ledStatus;           // Toggeln
} // fct ISR                         
