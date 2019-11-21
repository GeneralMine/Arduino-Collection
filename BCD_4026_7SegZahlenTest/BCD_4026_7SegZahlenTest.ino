/* Counter Test:  Ausgabe einer Zahl durch "Reset" und "clocken" von 4026 Zaehler */
 
#define counterResetPin  7             // Counter 4026 Reset-Pin #15
#define counterClockPin  6             // Counter 4026 Clock-Pin #1 
#define microSek 2                     // Pulsdauer für BCD 4026 Zaehler
#define anzDelay 2000                  // Anzeige Dauer in MilliSek

void setup()
{
  pinMode(counterResetPin, OUTPUT);    // Pin als Ausgang
  pinMode(counterClockPin, OUTPUT);    // Pin als Ausgang
} // fct setup 
 
void showZahl(int value)               //  zeigt Parameter "value" mit 7Seg-Ziffern an
{
  resetCounter();                      // Anzeige erst mal löschen                
  for(int i = 0; i < value; i++)       // "value" mal einen Clock Puls ausgeben 
  {
    digitalWrite(counterClockPin, HIGH);  // Clock-Pin auf HIGH setzen
    delayMicroseconds(microSek);          // warten bis HIGH-Pegel stabil ist                           
    digitalWrite(counterClockPin, LOW);   // Clock-Pin auf LOW setzen
    delayMicroseconds(microSek);          // warten bis LOW-Pegel stabil ist 
  }  // for
}  // fct

void resetCounter()           // setzt Zaehlerbaustein auf "0" (Reset)
{
  digitalWrite(counterResetPin, HIGH);   // Reset-Pin auf HIGH setzen
  delayMicroseconds(microSek);           // warten bis HIGH-Pegel stabil ist    
  digitalWrite(counterResetPin, LOW);    // Reset-Pin auf LOW setzen
  delayMicroseconds(microSek);           // warten bis LOW-Pegel stabil ist
}  // fct
 
void loop()                              
{
  showZahl(11);                          // mit Fkt "showZahl"  "11" anzeigen
  delay(anzDelay);                       // "x" milli-sec warten  
  showZahl(88);                          // mit Fkt "showZahl"  "88" anzeigen
  delay(anzDelay);                       // "x" milli-sec warten 
  showZahl(34);
  delay(anzDelay);
  resetCounter();                        // Zaehler auf "0"    
  delay(anzDelay);                       // "x" milli-sec warten
}  // loop
