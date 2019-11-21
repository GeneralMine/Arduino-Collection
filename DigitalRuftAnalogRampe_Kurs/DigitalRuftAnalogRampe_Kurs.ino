/*  Digital ruft analog
Dieser Sketch zeigt die Digital/Analog-Wandlung über eine Widerstandsleiter
Referenz:      http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/DigitalWrite
               http://arduino.cc/en/Reference/BitRead  */
               
#define VERSUCHE 5                           // Anzahl der Wiederholungen
#define BITANZAHL 6                          // 6 BIT Wandler
#define RESOLUTION 64                        // 6 Bit Wandler macht 64 Schritte
#define WARTEN 200                           // Zeit zwischen 2 Werten 
#define WARTEN2 1000                         // Zeit zwischen 2 Versuchen 

int pinArray[] = {8, 9, 10, 11, 12, 13};     // die 6 Pins des 6BIT DA Wandler
byte R2RPattern;                             // Bit Wert der gewandelt werden soll

void setup()
{
  for(int i = 0; i < BITANZAHL; i++)
  {
    pinMode(pinArray[i], OUTPUT);             // alle Pins als Ausgang programmieren
  }  // for
  R2RPattern = B000000;                       // Bitmuster zur Ansteuerung der digitalen Ausgänge
} // setup()

void loop()
{
  for(int m = 0; m < VERSUCHE; m++)
  {
    R2RPattern = B000000;                       // Startwert "0"
    for(int n = 0; n < RESOLUTION; n++)
    {
      for(int i = 0; i < BITANZAHL; i++)
      {                                         // wenn Bit = 1 dann Ausgang == HIGH, sonst LOW
        digitalWrite(pinArray[i], bitRead(R2RPattern, i) == 1?HIGH:LOW);
      } // for
      delay(WARTEN);  
      R2RPattern++;                             // Bitwert um eins erhöhen                          
    } // for
    delay(WARTEN2);
  }  // for
} // loop

