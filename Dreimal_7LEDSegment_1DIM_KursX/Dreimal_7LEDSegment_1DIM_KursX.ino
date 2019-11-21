/*   Steuert eine LED 7 Segment Anzeige an. Mit einem eindimensionalen Array
und der Funktion "bitRead"  */

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
int pinArray[] = {2,3,4,5,6,7,8,9};          // Array mit allen Segment-Ausgängen
int einerStelle = 11;
int zehnerStelle = 12;
int hunderterStelle = 13;
int gemeinsameKathode = 0;                   // Kathode dann = 1, Anode dann 0; 
                                                                         
void setup()
{
  for (int i=0; i<8; i++)                    // Schleife über alle Segmente
    pinMode(pinArray[i], OUTPUT);            // jeder Segmentpin als Ausgang
  pinMode(einerStelle, OUTPUT);
  pinMode(zehnerStelle, OUTPUT);
  pinMode(hunderterStelle, OUTPUT);
}   // setup

void loop()
{
//  test();
  anzeige(222);
}  // loop

void anzeige(int wert)
{
  int einer, zehner, hunderter;
  hunderter = (wert / 100); 
  zehner = (wert / 10);
  einer = wert - (hunderter * 100) - (zehner * 10);
  digitalWrite(einerStelle, LOW);
  digitalWrite(zehnerStelle, HIGH);
  digitalWrite(hunderterStelle, HIGH);
  ansteuerung(einer);
  digitalWrite(einerStelle, HIGH);
  digitalWrite(zehnerStelle, LOW);
  digitalWrite(hunderterStelle, HIGH);
  ansteuerung(zehner);  
  digitalWrite(einerStelle, HIGH);
  digitalWrite(zehnerStelle, HIGH);
  digitalWrite(hunderterStelle, LOW);
  ansteuerung(hunderter);
}    // fkt anzeige

void test()
{
  if (gemeinsameKathode)                    // 7-Segment Typ == gemeinsame Kathode
  {
    digitalWrite(einerStelle, HIGH);
    digitalWrite(zehnerStelle, HIGH);
    digitalWrite(hunderterStelle, HIGH);
    for (int i=0; i<3; i++)                 // dreimal Segmenttest
    {
      for (int j=0; j<8; j++)               // alle Segmente ansteuern 
        digitalWrite(pinArray[j], HIGH);    
      delay(800);                           // kurze Pause
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], LOW);     // alle Segmente aus
      delay(200);                           // kurze Pause
    }
    digitalWrite(einerStelle, LOW);
    digitalWrite(zehnerStelle, LOW);
    digitalWrite(hunderterStelle, LOW);
  }
  else
  {
    digitalWrite(einerStelle, LOW);
    digitalWrite(zehnerStelle, LOW);
    digitalWrite(hunderterStelle, LOW);
    for (int i=0; i<3; i++)
    {
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], LOW);
      delay(800);   
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], HIGH);
      delay(200);   
    }
    digitalWrite(einerStelle, HIGH);
    digitalWrite(zehnerStelle, HIGH);
    digitalWrite(hunderterStelle, HIGH);
  }
}  // fkt test  


void ansteuerung(int a)
{
  if (gemeinsameKathode)                    // 7-Segment Typ == gemeinsame Kathode
  {
    for (int j=7; j>=0; j--)              // Abfragen der Bits für die Segmente für Zahl i 
      digitalWrite(pinArray[7-j], bitRead(segmente[a], j) == 1?HIGH:LOW);
    delay(5);   
  }
  else
  {
    for (int j=7; j>=0; j--)              // Abfragen der Bits für die Segmente für Zahl i 
      digitalWrite(pinArray[7-j], bitRead(segmente[a], j) == 1?LOW:HIGH);
    delay(5);   
  }  
}    // fkt ansteuerung


/*
{ 
  if (gemeinsameKathode)                    // 7-Segment Typ == gemeinsame Kathode
  {
    for (int i=0; i<3; i++)                 // dreimal Segmenttest
    {
      for (int j=0; j<8; j++)               // alle Segmente ansteuern 
        digitalWrite(pinArray[j], HIGH);    
      delay(800);                           // kurze Pause
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], LOW);     // alle Segmente aus
      delay(200);                           // kurze Pause
    }
    delay(1000);
    
    for (int i=0; i<11; i++)                // alle 10 Ziffern und Dez Punkt 
    {                                       // nacheinander ansteuern               
      for (int j=7; j>=0; j--)              // Abfragen der Bits für die Segmente für Zahl i 
        digitalWrite(pinArray[7-j], bitRead(segmente[i], j) == 1?HIGH:LOW);
      delay(800);   
    }
    for (int j=0; j<8; j++)                 // am Ende alles wieder aus 
      digitalWrite(pinArray[j], LOW);
    delay(2000);                            // kurz warten, dann von vorne
  }
  else                                      // dieses Programm ist fast gleich  
  {                                         // aber für gemeinsame Anode       
    for (int i=0; i<3; i++)
    {
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], LOW);
      delay(800);   
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], HIGH);
      delay(200);   
    }
    delay(1000);
    
    for (int i=0; i<11; i++)
    {
      for (int j=7; j>=0; j--)              // Abfragen der Bits für die Segmente für Zahl i 
        digitalWrite(pinArray[7-j], bitRead(segmente[i], j) == 1?LOW:HIGH);
      delay(800);   
    }
    for (int j=0; j<8; j++)
      digitalWrite(pinArray[j], HIGH);
    delay(2000);
  }  
*/  
