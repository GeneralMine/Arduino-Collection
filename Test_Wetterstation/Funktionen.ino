void controlLED(int level, int adress)
{
  byte sendbyte;
  for(int led = 0; led < maxLED; led++)
  {
    if (led <= level)
      bitWrite(sendbyte, led, 1);
    else
      bitWrite(sendbyte, led, 0):
  }
 Wire.beginTransmission(adress);
 Wire.write(sendbyte);
 Wire.endTransmission();
}
