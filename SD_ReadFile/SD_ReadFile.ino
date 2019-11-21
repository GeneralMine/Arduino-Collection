/*     SD card read/write File
 
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4            */
 
#include <SD.h>

const int chipSelect = 10;
char myFileName[] = "WetterER.txt";
File myFile;

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
  Serial.println("initialization done.\n");

  myFile = SD.open(myFileName);              // open the file for reading
  if (myFile)
  {
    Serial.print("Inhalt von file:   ");
    Serial.println(myFileName);
    while (myFile.available())                 // read from the file until there's nothing else in it:
    {
    	Serial.write(myFile.read());
    }
    myFile.close();                            // close the file:
  }
  else
  {
    Serial.print("error opening file:   ");  // if the file didn't open, print an error:
    Serial.println(myFileName);             // if the file didn't open, print an error:
  }
}

void loop()
{
	// nothing happens after setup
}
