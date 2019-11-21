#include <Wire.h> 
#include <LiquidCrystal_I2C.h>      // wichtig muss neuste DFRobot Bibliothek sein mit behobenem RESET Fehler

LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
// LiquidCrystal_I2C lcd(0x27,16,2);     // ohne Adressbrücken fest 0x27; mit Adressbrücken default 0x20 (bis 0x27)

int backlightState = LOW;
long previousMillis = 0;
long interval = 1000;


void setup()
{
  lcd.init();                           // LCD aktivieren bzw initialisieren 
  lcd.backlight();                      // Hintergrund Beleuchtung == EIN                     
  lcd.home();                           // Cursor in Grundstellung links oben 
  lcd.setCursor(0,0);                   // Cursor in Position x,y; gezählt wird wieder von "0" ab 
  lcd.print("Hello, world!");           // Text ausgeben 
  lcd.setCursor(0,1);                   // Neue Position, hier Zeile 2 
  lcd.print("Here, I am!");             // Text ausgeben 
}  // setup

void loop()
{
  unsigned long currentMillis = millis();  
  if (currentMillis - previousMillis > interval)  // Zeitintervall Steuerung statt Funktion "delay()"
  {
    previousMillis = currentMillis;               // für nächstes Intervall Alte Zeit auf neue Zeit setzen 
    if (backlightState == LOW)                    // Hintergrundbeleuchtung blinken lassen
    {	
      backlightState = HIGH;
      lcd.backlight();
    }  // if
    else
    {
      backlightState = LOW;
      lcd.noBacklight();
    }  // else
  }  // if
}  // loop

