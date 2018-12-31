class SD_Card
{
  public:
  
  struct Daten
  {
    float Temp;
    float Humid;
  };
  
  File myFile;
  
  Daten inn;
  Daten aus;
  
  SD_Card(int pin)
  {
    SD.begin(pin);
  }
  
  bool schreiben()
  {
    /*
    inn.Temp = ldd.InnTemperatur(dht.readTemperature());
    inn.Humid = ldd.InnFeuchtigkeit(dht.readHumidity());
    
    aus.Temp = ldd.InnTemperatur(dht.readTemperature());
    aus.Humid = ldd.InnFeuchtigkeit(dht.readHumidity());
    
    return(true);
    */
    
  myFile = SD.open("Wetter.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) 
  {
    Serial.println("Writing to test.txt...");
    Serial.print("Au");
    myFile.print("Außentemperatur: ");
    myFile.print(aus.Temp);
    myFile.println("");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
    
  }
  
  bool lesen()
  {

  }
  
};
