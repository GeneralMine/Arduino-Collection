/*     SD card read/write File
 
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4   oder 10         */
 
boolean sdStart(int cs)
{
  Serial.print("Initializing SD card...   ");
  pinMode(10, OUTPUT);        
  if (SD.begin(cs))
  {
    Serial.println("initialization done.\n");
    return(true);
  }
  else
  {
    Serial.println("initialization failed!");
    return(false);
  }
}  // fct

boolean sdRead()
{
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
    return (true);
  }  // if
  else
  {
    return(false);
  }
}  // fct
  

void SDprintDigits(int digits, int dPunkt){
  // utility function for digital clock display: prints preceding colon and leading 0
  if (dPunkt)
    myFile.print(":");
  if(digits < 10)
    myFile.print('0');
  myFile.print(digits);
}

boolean writeSD_TimeDate()
{
  myFile = SD.open(myFileName, FILE_WRITE);
  if (myFile)                                  // if the file opened okay, write to it
  {
    SDprintDigits(hour(), false);
    SDprintDigits(minute(), true);
    SDprintDigits(second(), true);
    myFile.print(" ");
    myFile.print(day());
    myFile.print(" ");
    myFile.print(month());
    myFile.print(" ");
    myFile.println(year()); 
    myFile.close();                            // close the file
    return(true);
  }
  else
  {
    return(false);
  }
}  // fct

boolean writeSD_LM35Temp(float temp)
{
  myFile = SD.open(myFileName, FILE_WRITE);
  if (myFile)                                 // if the file opened okay, write to it
  {
    myFile.print("LM35 Temperatur:  ");       
    myFile.print(temp);                       
    myFile.write(0xB0);                       
    myFile.println(" C");                     
    myFile.close();                            // close the file
    return(true);
  }
  else
  {
    return(false);
  }
}  // fct

