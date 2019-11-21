/*   Taster per Interrupt lesen und LED ein- ausschaltem
Board             Interrupt-Nr  int.0   int.1    
Uno, Ethernet     Pin-Nr        D2      D3    

attachInterrupt(interrupt, ISR, mode)
  interrupt:    0 oder 1
  ISR:          Interrupt Service Routine      
  mode: - LOW trigger interrupt whenever pin is low, 
        - CHANGE trigger interrupt whenever pin changes 
        - RISING trigger when pin goes from low to high,   
        - FALLING trigger when pin goes from high to low. */

const int ledPin = 13;            // extra oder eingebaute LED
const int tasterPin = 2;          // Taster am int0

void setup()
{
  pinMode(ledPin, OUTPUT);        // LED Pin daher OUTPUT
  attachInterrupt(0, ISRledSchalten, CHANGE); // Interrupt=0, ISR-Name,
}  // setup                          Interrupt bei jedem Flankenwechsel 

void loop()
{
                                  //  beliebiger komplexter Code
}  // loop

void ISRledSchalten()                           // die Interrupt Fkt ISR
{                                               // Immer wenn sich Tastenzustand ändert wird Fkt aufgerufen 
  digitalWrite(ledPin, digitalRead(tasterPin)); // Gedrückt = EIN
} // fct ISR                                       sonst = AUS

