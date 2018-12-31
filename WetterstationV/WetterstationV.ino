#include <SD.h>
#include <LiquidCrystal.h>                                                                                    //including LCD-Libary
#include <Wire.h>                                                                                             //including I2C-Libary
#include <DHT.h>                                                                                            //including dht11-Libary for dht11-sensor
#include <SPI.h>                                                                                              //including Serial Peripheral Interface Bus
//#include <OneWire.h>                                                                                          //including OneWire-Libary

#include "LCD.h"
#include "SD_Card.h"

//Declaration

  //LCD
  const int LCD_RS = 12;
  const int LCD_Enable = 11;
  const int LCD_D4 = 5;
  const int LCD_D5 = 4;
  const int LCD_D6 = 3;
  const int LCD_D7 = 2;
  
  //I2C
  
  //DHT
    //#define DHTPIN 2
  
    // Uncomment whatever type you're using!
    //#define DHTTYPE DHT11   // DHT 11 
    #define DHTTYPE DHT22   // DHT 22  (AM2302)
    //#define DHTTYPE DHT21   // DHT 21 (AM2301)
  
  //SPI
  
  //OneWire
  
  //Strings

  //classes
  //class LCD;
  DHT dht(DHTPIN, DHTTYPE);
  
  LCD lcd1(1,2,3,4,5,6);
  
  SD_Card sd1(5);

void setup()
{
  dht.begin();
}

void loop()
{
  //sd1.schreiben();
}

