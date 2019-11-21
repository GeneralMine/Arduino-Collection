#include <LiquidCrystal.h>

const int LCD_RS = 12;
const int LCD_Enable = 11;
const int LCD_D4 = 5;
const int LCD_D5 = 4;
const int LCD_D6 = 3;
const int LCD_D7 = 2;

LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

String text1 = "Temperatur ";
String text2 = " Leider Geil";
String text_name = "Adrian Raiser";
String text_birthday = "10.02.1998";

int analogPin = A0;
float Temperature;
int cycles = 10;
int DELAY(100);
float result;
float sec;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  for(int i = 0; i<10; i++)
  {  
    Temperature = (5.0*100.0*analogRead(analogPin))/1024;
    result += Temperature;
    delay(DELAY);
  }
  
  result /= cycles;
  Serial.println(result);
  Ausgabe();
  result = 0;
}
