/*  This is a library for our I2C LED Backpacks
  Designed specifically to work with the Adafruit LED 7-Segment backpacks 
  ----> http://www.adafruit.com/products/881
  ----> http://www.adafruit.com/products/880
  ----> http://www.adafruit.com/products/879
  ----> http://www.adafruit.com/products/878

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73.
  For backpacks with 3 Address Select pins: 0x70 thru 0x77   */

#include <Wire.h>     // Enable this line if using Arduino Uno, Mega, etc.

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
//  matrix.begin(0x70);
  matrix.begin(0x71);
}  // setup

void loop()
{         

//  matrix.writeDigitNum(0, 4, true);  
//  matrix.writeDigitNum(2, 5, true);  
    matrix.drawColon(false);
//  matrix.writeDigitNum(3, 6, false);  
//  matrix.writeDigitNum(4, 7, false);  
  matrix.writeDisplay();
  delay(1000);
  
/*
  boolean drawDots = false;
  for (uint16_t counter = 0; counter < 9999; counter ++)
  {
    matrix.writeDigitNum(0, (counter / 1000), drawDots);  
    matrix.writeDigitNum(1, (counter / 100) % 10, drawDots);
    matrix.drawColon(drawDots);
    matrix.writeDigitNum(2, (counter / 10) % 10, drawDots);
    matrix.writeDigitNum(3, counter % 10, drawDots);

    matrix.writeDisplay();
    delay(10);    
  }  // for
*/  
}  // loop
