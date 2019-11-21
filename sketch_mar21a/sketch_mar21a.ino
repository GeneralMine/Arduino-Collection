#include <LiquidCrystal.h>
#include "LCD.h"
#define KEY_NOT_PRESSED'-'


LCD lcd(14,15,10,11,12,13);




void setup() {
  Serial.begin(9600);
  setKeyPad();
  //lcd.setTastatur(10);
}

void loop() {
  char myKey = readKey();
  if (myKey != KEY_NOT_PRESSED)
  {
    Serial.println(myKey);
    lcd.setTastatur(myKey);
  }
}
