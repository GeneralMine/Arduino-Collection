/*
  SD card file dump
 
 This example shows how to read a file from the SD card using the
 SD library and send it over the serial port.
 	
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4  oder 10                 */

#include <SD.h>

const int chipSelect = 10;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("\nInitializing SD card.....       ");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("harald.txt");
  if (dataFile)                     // if the file is available, write to it:
  {
    Serial.println("\nInhalt von File: harald.txt\n");
    while (dataFile.available())
    {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else                              // if the file isn't open, pop up an error:
  {
    Serial.println("error opening datalog.txt");
  } 
}

void loop()
{
}

