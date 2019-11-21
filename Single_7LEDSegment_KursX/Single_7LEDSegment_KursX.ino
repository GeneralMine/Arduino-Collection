/*   Steuert eine LED 7 Segment Anzeige an.
Es gibt welche mit gemeinsamer Kathode oder Anode
Auch auf die Anschlüsse achten, sind entweder an der langen oder schmalen Seite */

//                      a,b,c,d,e,f,g,DP     pro Segment 1 Byte mit "1" wenn EIN(aktiv) & "0" wenn "AUS"  
int segmente[11][8] = {{1,1,1,1,1,1,0,0},    // Segmente für Ziffer "0"
                       {0,1,1,0,0,0,0,0},    // Segmente für Ziffer "1"
                       {1,1,0,1,1,0,1,0},    // Segmente für Ziffer "2"
                       {1,1,1,1,0,0,1,0},    // Segmente für Ziffer "3"
                       {0,1,1,0,0,1,1,0},    // Segmente für Ziffer "4"
                       {1,0,1,1,0,1,1,0},    // Segmente für Ziffer "5"
                       {1,0,1,1,1,1,1,0},    // Segmente für Ziffer "6"
                       {1,1,1,0,0,0,0,0},    // Segmente für Ziffer "7"
                       {1,1,1,1,1,1,1,0},    // Segmente für Ziffer "8"
                       {1,1,1,1,0,1,1,0},    // Segmente für Ziffer "9"
                       {0,0,0,0,0,0,0,1}};   // Segmente für  "Dezimal Punkt

int pinArray[] = {2,3,4,5,6,7,8,9};          // Array mit allen Segment-Ausgängen  
int gemeinsameKathode = 1;                   // Kathode dann = 1, Anode dann 0; 
                                                                         
void setup()
{
  for (int i=0; i<8; i++)                    // Schleife über alle Segmente
    pinMode(pinArray[i], OUTPUT);            // jeder Segmentpin als Ausgang 
} // setup
 
void loop()
{ 
  if (gemeinsameKathode)                    // 7-Segment Typ == gemeinsame Kathode
  {
    for (int i=0; i<3; i++)                 // dreimal Segment-Test, alle LED (Segmente) blinken
    {
      for (int j=0; j<8; j++)               // alle 7 Segmente plus DP ansteuern 
        digitalWrite(pinArray[j], HIGH);    
      delay(800);                           // kurze Pause
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], LOW);     // alle 7 Segmente aus
      delay(200);                           // kurze Pause
    }  // for
    delay(1000);
    
    for (int i=0; i<11; i++)                // Ziffern 0 - 9 und Dez Punkt 
    {                                       // nacheinander ansteuern               
      for (int j=0; j<8; j++)               // Alle Segmente für Ziffer "i" ansteuern 
        digitalWrite(pinArray[j], (segmente[i][j]==1)?HIGH:LOW);  // Kurzform
      delay(800);   
    }  // for 
    for (int j=0; j<8; j++)                 // am Ende alles wieder aus 
      digitalWrite(pinArray[j], LOW);
    delay(2000);                            // kurz warten, dann von vorne
  }  // if gem. Kathode
  // keine gemeinsame Kathode also Anode
  else                                      // dieses Programm ist fast gleich  
  {                                         // aber für gemeinsame Anode       
    for (int i=0; i<3; i++)                 // dreimal Segment-Test
    {
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], LOW);
      delay(800);   
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], HIGH);
      delay(200);   
    }  // for 
    delay(1000);
    
    for (int i=0; i<11; i++)              // 0 - 9 und Dez Punkt
    {                                     // nacheinander ansteuern 
      for (int j=0; j<8; j++)
        digitalWrite(pinArray[j], (segmente[i][j]==1)?LOW:HIGH);
      delay(800);   
    }  // for
    for (int j=0; j<8; j++)
      digitalWrite(pinArray[j], HIGH);
    delay(2000);
  }  // else gem. Anode  
}   // loop
