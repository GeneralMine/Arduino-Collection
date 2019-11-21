/* Steuert eine LED 7 Segment Anzeige an. Mit einem eindimensionalen Array
und der Funktion "bitRead"; einstellbar ob gemeinsame Anode oder Kathode */

//  Segment:          abcdefgDP  wenn Segment aktiv (EIN) dann Bit = "1", sonst Bit = "0"                    
byte segmente[11] = {B11111100,    // Ziffer "0"
                     B01100000,    // Ziffer "1"
                     B11011010,    // Ziffer "2"
                     B11110010,    // Ziffer "3"
                     B01100110,    // Ziffer "4"
                     B10110110,    // Ziffer "5"
                     B10111110,    // Ziffer "6"
                     B11100000,    // Ziffer "7"
                     B11111110,    // Ziffer "8"
                     B11110110,    // Ziffer "9"
                     B00000001};   // Dezimal-Punkt
int pinArray[] = {2,3,4,5,6,7,8,9};          // Array mit allen Segment-Ausgängen (Pins)  
int gemeinsameKathode = 1;                   // Kathode dann = 1, Anode dann 0; 
                                                                         
void setup()
{
  for (int i=0; i<8; i++)                    // Schleife über alle 7 Segmente plus Dezimal Punkt, d.h. 8 
    pinMode(pinArray[i], OUTPUT);            // jeder Segmentpin als Ausgang, Index von 0 - 7, d.h. i<8 
} // setup

void loop()
{ 
  if (gemeinsameKathode)                    // 7-Segment Typ == gemeinsame Kathode
  {                                         // Alle Segmente und DP ansteuern 
    for (int i=0; i<3; i++)                 // dreimal Segmenttest, d.h. 3 mal blinken lassen
    {
      for (int j=0; j<8; j++)               // alle Segmente ansteuern --> HIGH 
        digitalWrite(pinArray[j], HIGH);    // --> HIGH
      delay(800);                           // kurze Pause
      for (int j=0; j<8; j++)               // alle Segmente aus 
        digitalWrite(pinArray[j], LOW);     // --> LOW
      delay(200);                           // kurze Pause
    }  // for
    delay(1000);
    
    for (int i=0; i<11; i++)                // alle 10 Ziffern und Dez Punkt nacheinander anzeigen 
    {                                       // d.h. 0-9 und DP also 11 nacheinander ansteuern               
      for (int j=7; j>=0; j--)              // Abfragen der Bits für die Segmente für Ziffer i 
        digitalWrite(pinArray[7-j], bitRead(segmente[i], j) == 1?HIGH:LOW);
      delay(800);                           // EIN Zeit für eine Ziffer  
    }  // for
    for (int j=0; j<8; j++)                 // nach letzter Ziffer alles wieder aus 
      digitalWrite(pinArray[j], LOW);       // --> LOW 
    delay(2000);                            // kurz warten, dann das ganze von vorne
  }  // if
  else                                      // dieses Programm ist fast gleich  
  {                                         // aber für gemeinsame Anode       
    for (int i=0; i<3; i++)
    {
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], LOW);     // Statt HIGH  hier LOW
      delay(800);   
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], HIGH);    // Statt LOW  hier HIGH
      delay(200);   
    }  // for
    delay(1000);
    
    for (int i=0; i<11; i++)
    {
      for (int j=7; j>=0; j--)              // Abfragen der Bits für die Segmente für Zahl i 
        digitalWrite(pinArray[7-j], bitRead(segmente[i], j) == 1?LOW:HIGH); // statt HIGH:LOW hier LOW:HIGH
      delay(800);   
    }  // for
    for (int j=0; j<8; j++)
      digitalWrite(pinArray[j], HIGH);
    delay(2000);
  }  // else  
}   // loop
