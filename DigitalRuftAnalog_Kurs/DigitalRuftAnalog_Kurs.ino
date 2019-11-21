/*  Digital ruft analog
Dieser Sketch zeigt die Digital/Analog-Wandlung über eine Widerstandsleiter
Referenz:      http://arduino.cc/en/Reference/PinMode
               http://arduino.cc/en/Reference/Constants
               http://arduino.cc/en/Reference/For
               http://arduino.cc/en/Reference/DigitalWrite
               http://arduino.cc/en/Reference/BitRead  */
               
               
int pinArray[] = {8, 9, 10, 11, 12, 13};     // die 6 Pins des 6BIT DA Wandler
byte R2RPattern;                             // Bit Wert der gewandelt werden soll

void setup()
{
  for(int i = 0; i < 6; i++)
  {
    pinMode(pinArray[i], OUTPUT);             // alle Pins als Ausgang programmieren
  }  // for
  R2RPattern = B011111;                       // Bitmuster zur Ansteuerung der digitalen Ausgänge
} // setup()

void loop(){
  for(int i = 0; i < 6; i++)
  {                                           // wenn Bit = 1 dann Ausgang == HIGH, sonst LOW
    digitalWrite(pinArray[i], bitRead(R2RPattern, i) == 1?HIGH:LOW);
  } // for
} // loop

