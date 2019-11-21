/* Counter Test:  Ausgabe von Zahlen durch "Reset" und "clocken" von 4026 Zaehler 
und Hochzaehlern  von 0 bis 99 */
 
#define counterResetPin  7             // BCD_4026 Reset-Pin #15
#define counterClockPin  6             // BCD_4026 Clock-Pin #1 
#define microSek 2                     // Pulsdauer für BCD 4026 Zaehler
#define ANZ_DELAY 2000                 // Anzeige Dauer in MilliSek
#define COUNTER_DELAY 100              // Anzeige Dauer in MilliSek


void setup()
{
  pinMode(counterResetPin, OUTPUT);    // Pin als Ausgang
  pinMode(counterClockPin, OUTPUT);    // Pin als Ausgang
  Serial.begin(9600);
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
  Serial.print("Zahlen anzeigen:   ");
  showZahl(11);                          // mit Fkt "showZahl"  "11" anzeigen
  Serial.print("11;  ");
  delay(ANZ_DELAY);                      // "x" milli-sec warten  
  showZahl(88);                          // mit Fkt "showZahl"  "88" anzeigen
  Serial.print("88;  ");
  delay(ANZ_DELAY);                      // "x" milli-sec warten 
  showZahl(34);
  Serial.print("34;  ");
  delay(ANZ_DELAY);
  resetCounter();                        // Zaehler auf "0"    
  Serial.println("00");
  delay(ANZ_DELAY);                      // "x" milli-sec warten
  Serial.println("Von 0 nach 99 hochzaehlen:   ");
  for (int i=0; i<100; i++)
  {
    showZahl(i);                          // mit Fkt "showZahl"  "11" anzeigen
    Serial.print(i);
    Serial.println("");
    delay(COUNTER_DELAY);
  }  // for
  Serial.println("");
}  // loop
