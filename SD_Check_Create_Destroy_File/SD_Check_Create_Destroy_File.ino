/*
  SD card basic file example
 This example shows how to create and destroy an SD card file 	
 
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4                */
 
#include <SD.h>

File myFile;
const int chipSelect = 10;    // kann jeder Pin sein

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...   ");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
  pinMode(10, OUTPUT);

  if (!SD.begin(chipSelect))
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  if (SD.exists("example.txt"))
  {
    Serial.println("example.txt exists.");
  }
  else
  {
    Serial.println("example.txt doesn't exist.");
  }
  Serial.println("Creating example.txt...");
  myFile = SD.open("example.txt", FILE_WRITE);
  myFile.close();
  if (SD.exists("example.txt"))                      // Check to see if the file exists: 
  {
    Serial.println("example.txt exists.");
  }
  else
  {
    Serial.println("example.txt doesn't exist.");  
  }
  Serial.println("Removing example.txt...");
  SD.remove("example.txt");                          // delete the file:
  if (SD.exists("example.txt"))
  { 
    Serial.println("example.txt exists.");
  }
  else
  {
    Serial.println("example.txt doesn't exist.");  
  }
}  // setup

void loop()
{
  // nothing happens after setup finishes.
}

