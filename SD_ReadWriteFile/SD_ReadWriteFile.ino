/*     SD card read/write a File "FnameX.txt"
  * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4  oder 10    On the Ethernet Shield, CS is pin 4.      

Note that even if standard CS is not used as the CS pin for SD, the hardware SS pin 
(10 on most Arduino boards, 53 on Mega) must be left as an output or SD lib. fcts. will not work. */
 
#include <SD.h>                       // Library

const int chipSelect = 10;            // Select-Pin für SPI Bauteil (hier SD-Card) 
char myFileName[] = "wetter11.txt";   // Filename, max 8 Zeichen + 3 Extension
File myFile;                          // File Object definieren
    
void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...   ");
  pinMode(10, OUTPUT);
  if (!SD.begin(chipSelect))           // SD Karte (Object) initialisieren 
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.\n");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(myFileName, FILE_WRITE);    // or "FILE_READ"
  if (myFile)                                  // if file opened okay, write to it
  {
    Serial.print("Writing to:  \"");           // Ausgabe eines  "  mit \" 
    Serial.print(myFileName);
    Serial.print("\" : ");
    myFile.println("testing 1, 2, 3.");
    myFile.close();                            // close the file
    Serial.println(" --> done.\n");
  }  // if
  else
  {
    Serial.print("error opening for write: "); // if file didn't open, print error
    Serial.println(myFileName);
  }  // else

  myFile = SD.open(myFileName);                // re-open the file for reading
  if (myFile)                                  // if file opened okay, read it
  {
    Serial.print("Inhalt von :   \"");
    Serial.print(myFileName);
    Serial.println("\"");
    while (myFile.available())                 // read from file until there's nothing else in it:
    {
    	Serial.write(myFile.read());           // read file
    }
    myFile.close();                            // close file:
  }  // if
  else
  {
    Serial.print("error opening for read:  "); // if file didn't open, print error
    Serial.println(myFileName);
  }  // else
}  // setup

void loop()
{
	// nothing happens after setup
}
