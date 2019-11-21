/*  LCD - Hello World: Demonstrates the use a 16x2 or 20x4 LCD display.
The LiquidCrystal library works with all LCD displays that are compatible with the 
Hitachi HD44780 driver. This sketch prints "TEXT" to the LCD and shows the time. */
   
const int LCD_RS = 16;            // == Analog A2; LCD RS Register Select Pin (4)
const int LCD_Enable = 15;        // == Analog A1; LCD ENABLE Pin (6)
const int LCD_D4 = 10;            // LCD Data4 Pin (11)
const int LCD_D5 = 11;            // LCD Data5 Pin (12)
const int LCD_D6 = 12;            // LCD Data6 Pin (13)
const int LCD_D7 = 13;            // LCD Data7 Pin (14)
#define  ROWS  4                  // Anzahl Zeilen 2 oder 4
#define  COLUMNS 20               // Anzahl Spalten 16 oder 20

#include <LiquidCrystal.h>         // include the library code:

LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);  // initialize library
                                                                // with nr. of interface pins
void setup()
{
  lcd.begin(COLUMNS, ROWS);        // set up the LCD's number of columns and rows: 
  lcd.setCursor(0, 0);             // Cursor to column 1, line 1; 
  lcd.print("hello, world!");      // Print a message to the LCD.
  lcd.setCursor(0, 1);             // Cursor to column 1, line 2; 
  lcd.print("hello, Esslingen!");  // Print a message to the LCD.
  if (ROWS == 4)                   // 4 Zeilen verfügbar ? 
  {
    lcd.setCursor(0, 2);            // Cursor to column 0, line 3; 
    lcd.print("hello, ARDUINO's");  // Print a message to the LCD.
  }  // if
}  // setup

void loop()
{
  // (note: line 1 is the second row, since counting begins with 0):
  if (ROWS == 4)                     // grosses LCD? 
  {
    lcd.setCursor(0, 3);             // Cursor to column 1, line 4; 
    lcd.print(millis()/1000);        // print the number of seconds since reset:
  }  // if
  else {                             // kleines Display 
    lcd.setCursor(14, 0);            // Cursor to column 15, line 1; 
    lcd.print(millis()/1000);        // print the number of seconds since reset:
  }  // else  
  delay(200);                      // kurze Verzögerung
}  // loop

