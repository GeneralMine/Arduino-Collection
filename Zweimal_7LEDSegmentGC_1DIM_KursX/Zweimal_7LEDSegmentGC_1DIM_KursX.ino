/*   Steuert zwei LED 7-Segment Anzeigen per Multiplex an und zeigt den Wert
eines Potis an. Mit eindimensionalen Array & Fkt "bitRead"; gemeinsame Kathode */
//           Segment  abcdefgDP
byte segmente[11] = {B11111100,    // 0
                     B01100000,    // 1
                     B11011010,    // 2
                     B11110010,    // 3
                     B01100110,    // 4
                     B10110110,    // 5
                     B10111110,    // 6
                     B11100000,    // 7
                     B11111110,    // 8
                     B11110110,    // 9
                     B00000001};   // Punkt
int pinArray[] = {2,3,4,5,6,7,8,9};   // Array mit allen Segment-Ausgängen incl. DP
// int pinArray[] = {2,3,4,5,6,7,8};   // Array mit allen Segment-Ausgängen ohne DP
int einerStelle = 12;              // Pin 12 als Ausgang zur Ansteuerung des Transistors "einerStelle"
int zehnerStelle = 13;             // Pin 13 als Ausgang zur Ansteuerung des Transistors "zehnerStelle"
int potiPin = A0;                  // Nummer Analogeingang zum Lesen des Potiwertes
int potiWert;                      // Poti Wert speichern
int zweiStellenZahl;               // umgewandelte 2 stellige Poti Zahl speichern
                                                                         
void setup()
{
//  for (int i=0; i<7; i++)        // Schleife über alle Segmente, außer DP
  for (int i=0; i<8; i++)          // Schleife über alle Segmente, mit DP
    pinMode(pinArray[i], OUTPUT);  // jeder Segmentpin als Ausgang
  pinMode(einerStelle, OUTPUT);    // Ansteuerung Trans 1 als Output
  pinMode(zehnerStelle, OUTPUT);   // Ansteuerung Trans 2 als Output 
  test();                          // alle Segmente aufblinken lassen    
}   // setup

void loop()
{
  potiWert = analogRead(potiPin);  // Wert des Potentiometer lesen
  zweiStellenZahl = map(potiWert, 0, 1023, 0, 99);   // map 0 - 1023 nach 0 - 99
  anzeige(zweiStellenZahl);        // Fkt. zeigt Wert auf 2 Stellen an
  
}  // loop

void anzeige(int wert)
{
  int einer, zehner;                // Variable für Einer und Zehner Stelle
  zehner = wert / 10;               // Zehnerstelle berechnen
  einer = wert - (zehner * 10);     // Einerstelle berechnen
  digitalWrite(einerStelle, HIGH);  // Transistor für Einerstelle ein = HIGH (NPN)  
  digitalWrite(zehnerStelle, LOW);  // Transistor für Zehnerstelle aus = LOW (NPN)
  ansteuerung(einer);               // Segmente der Einerstelle ansteuern 
  digitalWrite(einerStelle, LOW);   // Transistor für Einerstelle aus = LOW (NPN) 
  digitalWrite(zehnerStelle, HIGH); // Transistor für Zehnerstelle ein = HIGH (NPN)
  ansteuerung(zehner);              // Segmente der Zehnerstelle ansteuern 
}    // fkt anzeige

void ansteuerung(int a)
{
//  for (int j=7; j>=0; j--)    // Abfragen der Bits für die Segmente für Zahl i 
//    digitalWrite(pinArray[7-j], bitRead(segmente[a], j) == 1?HIGH:LOW);
  for (int j=7; j>0; j--)    // Abfragen der Bits für die Segmente für Zahl i 
    digitalWrite(pinArray[7-j], bitRead(segmente[a], j) == 1?HIGH:LOW);
  delay(5);   
}    // fkt ansteuerung

void test()
{
  digitalWrite(einerStelle, HIGH);        // Transistor für Einerstelle ein = HIGH (NPN)
  digitalWrite(zehnerStelle, HIGH);       // Transistor für Zehnerstelle ein = HIGH (NPN)
  for (int i=0; i<3; i++)                 // dreimal Segmenttest
  {
//    for (int j=0; j<7; j++)               // alle Segmente außer DP ansteuern 
    for (int j=0; j<8; j++)               // alle Segmente mit DP ansteuern 
      digitalWrite(pinArray[j], HIGH);    
    delay(800);                           // kurze Pause
//    for (int j=0; j<7; j++)             // alle Segmente außer DP ansteuern 
    for (int j=0; j<8; j++)               // alle Segmente mit DP ansteuern 
      digitalWrite(pinArray[j], LOW);     // alle Segmente aus
    delay(200);                           // kurze Pause
  }
  digitalWrite(einerStelle, LOW);         // Transistor für Einerstelle aus = LOW (NPN)
  digitalWrite(zehnerStelle, LOW);        // Transistor für Zehnerstelle aus = LOW (NPN)
}  // fkt test  

