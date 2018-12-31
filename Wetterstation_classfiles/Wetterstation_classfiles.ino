#include <LiquidCrystal.h>                                                                                    //including LCD-Libary
#include <Wire.h>                                                                                             //including I2C-Libary
#include <dht11.h>                                                                                            //including dht11-Libary for dht11-sensor
#include <SPI.h>                                                                                              //including Serial Peripheral Interface Bus
//#include <OneWire.h>                                                                                          //including OneWire-Libary

//Declaration

  //LCD
  const int LCD_RS = 12;
  const int LCD_Enable = 11;
  const int LCD_D4 = 5;
  const int LCD_D5 = 4;
  const int LCD_D6 = 3;
  const int LCD_D7 = 2;
  
  LiquidCrystal lcd (LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
  
  //I2C
  
  //dhc11
  
  //SPI
  
  //OneWire
  
  //Strings

  //classes
  class LCD;
LCD lcd1();
void setup()
{
  //LCD lcd1();
}

void loop()
{
   lcd1.InnTemperatur(27.3);
}

