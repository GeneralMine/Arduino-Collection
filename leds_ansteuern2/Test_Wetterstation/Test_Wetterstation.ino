#include <Wire.h>

int adress = 0x38 

int maxLED = 8;

byte analogPotiPin = 0

setup()
{
  Wire.begin();
  Serial.begin(9600);
}

loop()
{
  int mappedValue = map(analogRead(analogPotiPin), 0, 1000, 0, maxLED);
  controlLED(mappedValue, adress);
}
