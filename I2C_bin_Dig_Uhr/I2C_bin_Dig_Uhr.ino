#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#define STD_COUNTER 4

Adafruit_7segment seg7 = Adafruit_7segment();
Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

unsigned char hour = 8, minute = 00, second;
int setH, setM, setS;

unsigned int interval = 21000;       // Intervallzeit 
unsigned long alteZeit;    // Zeit-Variable
int stdCounter = 0;


void setup()
{
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);        // pass in the address
  seg7.begin(0x71);
  alteZeit = millis();       // jetzigen Zeitstempel merken

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
  
  if((millis() - alteZeit) > interval)
  {
    seg7.writeDigitNum(0, (hour / 10), false);  // 0 ist hoechste Stelle --> links  
    seg7.writeDigitNum(1, (hour % 10), false);  // 1 ist zweithoechste Stelle
    seg7.drawColon(true);                         // Doppelpunkt == EIN 
    seg7.writeDigitNum(3, (minute / 10), false);  // Stelle 2 gibt es nicht --> 3
    seg7.writeDigitNum(4, (minute % 10), false);  // 4 ist kleinste Stelle --> rechts
    seg7.writeDisplay();
    if (stdCounter < STD_COUNTER)
    {
      stdCounter++;
    }
    else
    {  
      alteZeit = millis();
      stdCounter = 0;
    }  
  }  // if
  else
  {
    seg7.writeDigitNum(0, (minute / 10), false);  // 0 ist hoechste Stelle --> links  
    seg7.writeDigitNum(1, (minute % 10), false);  // 1 ist zweithoechste Stelle
    seg7.drawColon(true);                         // Doppelpunkt == EIN 
    seg7.writeDigitNum(3, (second / 10), false);  // Stelle 2 gibt es nicht --> 3
    seg7.writeDigitNum(4, (second % 10), false);  // 4 ist kleinste Stelle --> rechts
    seg7.writeDisplay();
  }  // else  

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

