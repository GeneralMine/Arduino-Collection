/*    This is a library for our I2C LED Backpacks
 * Designed specifically to work with the Adafruit LED Matrix backpacks
 * ----> http://www.adafruit.com/products/872
 * ----> http://www.adafruit.com/products/871
 * ----> http://www.adafruit.com/products/870
 *
 * These displays use I2C to communicate, 2 pins are required to
 * interface. There are multiple selectable I2C addresses. For backpacks
 * with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
 * with 3 Address Select pins: 0x70 thru 0x77    */

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

// Adafruit_7segment seg7 = Adafruit_7segment();
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

unsigned char hour = 12, minute = 37, second;
int setH, setM, setS;

void setup()
{
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
//  seg7.begin(0x71);

}  // setup

static const uint8_t PROGMEM
smile_bmp[] =
{
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
}
,
neutral_bmp[] =
{
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10111101,
  B10000001,
  B01000010,
  B00111100
}
,
frown_bmp[] =
{
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};

void loop()
{
//    seg7.writeDigitNum(0, 1, false);  
//    seg7.writeDigitNum(1, 2, false);
//    seg7.drawColon(true);
//    seg7.writeDigitNum(3, 3, false);
//    seg7.writeDigitNum(4, 5, false);
//    seg7.writeDisplay();
  
  matrix.clear();
  for ( int i = 0; i <= 7; i++) {
    if ( bitRead(hour / 10, i) ) {
      matrix.drawPixel(0, 7 - i, LED_RED);
    }
  }
  for ( int i = 0; i <= 7; i++) {
    if ( bitRead(hour % 10, i) ) {
      matrix.drawPixel(1, 7 - i, LED_RED);
    }
  }
  for ( int i = 0; i <= 7; i++) {
    if ( bitRead(minute / 10, i) ) {
      matrix.drawPixel(3, 7 - i, LED_YELLOW);
    }
  }
  for ( int i = 0; i <= 7; i++) {
    if ( bitRead(minute % 10, i) ) {
      matrix.drawPixel(4, 7 - i, LED_YELLOW);
    }
  }
  for ( int i = 0; i <= 7; i++) {
    if ( bitRead(second / 10, i) ) {
      matrix.drawPixel(6, 7 - i, LED_GREEN);
    }
  }
  for ( int i = 0; i <= 7; i++) {
    if ( bitRead(second % 10, i) ) {
      matrix.drawPixel(7, 7 - i, LED_GREEN);
    }
  }
  matrix.writeDisplay();

  second++;
  if (second > 59) {
    second = 0;
    minute++;
  }
  if (minute > 59) {
    minute = 0;
    hour++;
  }
  if (hour > 23){
    hour = 0;
  }

  setH = 255;
  setM = 255;
  setS = 255;  
  
  while( Serial.available() > 0) {
    unsigned char code = Serial.read();
    Serial.print("Char received: ");
    Serial.println((String)code);
    switch( code ){
      case 'H':
        setH = Serial.parseInt();
        Serial.print("   H found: ");
        Serial.println(setH);
        break;
      case 'M':
        setM = Serial.parseInt();
        Serial.print("   M found: ");
        Serial.println(setM);
        break;
      case 'S':
        setS= Serial.parseInt();
        Serial.print("   S found: ");
        Serial.println(setS);
       break;
      default:
        Serial.println("   Wrong Char found!");
        break;
    }  // switch
    if( Serial.read() == '\n') {
      if( setH != 255 ) hour = setH;
      if( setM != 255 ) minute = setM;
      if( setS != 255 ) second = setS;
    }  // if  
  }  // while
  delay(1000);
}  // loop  
  
  /*
  matrix.clear();
   matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_GREEN);
   matrix.writeDisplay();
   delay(500);

   matrix.clear();
   matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_YELLOW);
   matrix.writeDisplay();
   delay(500);

   matrix.clear();
   matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_RED);
   matrix.writeDisplay();
   delay(500);

   matrix.clear();      // clear display
   matrix.drawPixel(0, 0, LED_GREEN);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(500);

   matrix.clear();
   matrix.drawLine(0,0, 7,7, LED_YELLOW);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(500);

   matrix.clear();
   matrix.drawRect(0,0, 8,8, LED_RED);
   matrix.fillRect(2,2, 4,4, LED_GREEN);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(500);

   matrix.clear();
   matrix.drawCircle(3,3, 3, LED_YELLOW);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(500);

   matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
   matrix.setTextSize(1);
   matrix.setTextColor(LED_GREEN);
   for (int8_t x=7; x>=-36; x--) {
   matrix.clear();
   matrix.setCursor(x,0);
   matrix.print("Hello");
   matrix.writeDisplay();
   delay(100);
   }
   matrix.setRotation(3);
   matrix.setTextColor(LED_RED);
   for (int8_t x=7; x>=-36; x--) {
   matrix.clear();
   matrix.setCursor(x,0);
   matrix.print("World");
   matrix.writeDisplay();
   delay(100);
   }
   matrix.setRotation(0);
   */

