#include <LiquidCrystal.h>                                                                                    //including LCD-Libary
#include <Wire.h>                                                                                             //including I2C-Libary
#include <dhc11.h>                                                                                            //including dht11-Libary for dht11-sensor
#include <SPI.h>                                                                                              //including Serial Peripheral Interface Bus
#include <OneWire.h>                                                                                          //including OneWire-Libary

//Pins
int analogPin = 1;

const int LCD_RS = 12;
const int LCD_Enable = 11;
const int LCD_D4 = 5;
const int LCD_D5 = 4;
const int LCD_D6 = 3;
const int LCD_D7 = 2;

String tempString1 = "Temperatur: ";
String tempString2 = "° C";
String humidString1 = "Feuchtigkeit: ";
String humidString2 = "%";

int I2C_ = 0x00;

LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);                                       //initialising LC-Display

int cycles = 10

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  float temp = Read_Temp();
  
  LCD_Ausgabe(temp);
}
