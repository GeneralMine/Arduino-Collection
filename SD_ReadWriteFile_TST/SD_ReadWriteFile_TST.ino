/*     SD card read/write File
 
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4   oder 10         */
 
#include <SD.h>

const int chipSelect = 10;
char myFileName[] = "test2.txt";
File myFile;
int sdCardOK = false;
int lineCounter = 0;


void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...   ");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(10, OUTPUT);
   
  if (SD.begin(chipSelect))
  {
    Serial.println("initialization done.\n");
    sdCardOK =true;
  }
  else
  {
    Serial.println("initialization failed!");
    sdCardOK = false;
  }
}  // setup

void loop()
{
  if (sdCardOK)
  {
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open(myFileName, FILE_WRITE);
    if (myFile)                                  // if the file opened okay, write to it
    {
      Serial.print("Writing to:  ");
      Serial.print(myFileName);
      Serial.print(" : ");
      myFile.print(lineCounter++);
      myFile.print(" : ");
      myFile.println("testing 1, 2, 3.");
	// close the file:
      myFile.close();                            // close the file
      Serial.println("done.");
    }
    else
    {
      Serial.print("error opening: ");  // if the file didn't open, print an error
      Serial.println(myFileName);
    }
    delay(5000);

    myFile = SD.open(myFileName);                // re-open the file for reading
    if (myFile)
    {
      Serial.print("Inhalt von :   ");
      Serial.println(myFileName);
      while (myFile.available())                 // read from the file until there's nothing else in it:
      {
    	Serial.write(myFile.read());
      }
      myFile.close();                            // close the file:
    }
    else
    {
      Serial.print("error opening: ");  // if the file didn't open, print an error
      Serial.println(myFileName);
    }
    delay(5000);
  }  // if
}  // loop
