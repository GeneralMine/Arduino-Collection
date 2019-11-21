/* KeyPad (Digital) und  LCD Display.  Dieser Sketch zeigt die Ansteuerung eines
KeyPads (Digital). Die Anzeige der gedrückten Taste erfolgt im LCD Display    */

#include <LiquidCrystal.h>         // include the library code:
#define KEY_NOT_PRESSED '-'        // Wird benötigt, wenn keine Taste gedrückt wird
#define  ROWS  4                   // Anzahl Zeilen 2 oder 4
#define  COLUMNS 20                // Anzahl Spalten 16 oder 20

const byte LCD_RS = 16;            // == Analog A2; LCD RS Register Select Pin (4)
const byte LCD_Enable = 15;        // == Analog A1; LCD ENABLE Pin (6)
const byte LCD_D4 = 10;            // LCD Data4 Pin (11)
const byte LCD_D5 = 11;            // LCD Data5 Pin (12)
const byte LCD_D6 = 12;            // LCD Data6 Pin (13)
const byte LCD_D7 = 13;            // LCD Data7 Pin (14)

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
  Serial.begin(9600);              // Serielle Ausgabe vorbereiten
  setKeyPad();
  lcd.begin(COLUMNS, ROWS);        // set up the LCD's columns & rows, here 20x4 oder 16x2 
  lcd.setCursor(0, 0);             // Cursor to column 1, line 1; --> counting begins with 0!
  lcd.print("hello, world!");      // Print a message to the LCD.
  lcd.setCursor(0, 1);             // Cursor to column 1, line 2; 
  lcd.print("hello, Esslingen!");  // Print a message to the LCD.
  lcd.setCursor(0, 2);             // Cursor to column 1, line 3; 
  lcd.print("hello, ARDUINO's");   // Print a message to the LCD.
  lcd.setCursor(0, 3);             // Cursor to column 1, line 4; 
  lcd.print("Sek.: ");             // Print a message to the LCD.
  lcd.setCursor(10, 3);            // Cursor to column 11, line 4; 
  lcd.print("Taste: ");            // Print a message to the LCD.
}  // setup

void loop() {
  char myKey = readKey();          // Abfragen des gedrückten Tasters
  if(myKey != KEY_NOT_PRESSED)     // Abfrage, ob irgendein Taster gedrückt
    Serial.println(myKey);         // Ausgabe des Tastenzeichens  
  lcd.setCursor(6, 3);             // Cursor to column 7, line 4; --> counting begins with 0)
  lcd.print(millis()/1000);        // print the number of seconds since reset:
  if(myKey != KEY_NOT_PRESSED) {   // Abfrage, ob irgendein Taster gedrückt
    lcd.setCursor(17, 3);          // Cursor to column 18, line 4; 
    lcd.print(myKey);              // print the number of seconds since reset:
  }  // if  
}  // loop
