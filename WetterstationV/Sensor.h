class Sensor : public DHT
{
  private:
  float temp;
  float humid;
  
  public:
  
  Sensor(int DHTPIN):DHT(DHTPIN, DHTTYPE)
  {
    begin();
  }
  
  float getTemp()
  {
    temp = readTemperature();
    return(temp);
  }
  
  float getHumid()
  {
    humid = readHumidity();
    return(humid);
  }
  
  
};
