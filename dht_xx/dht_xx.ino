// Example testing sketch for various DHT humidity/temperature sensors

#include "DHT.h"                // Library
#define DHTPIN 2                // what pin DHT is connected to

// Uncomment whatever type you're using!
// #define DHTTYPE DHT11        // DHT 11 
#define DHTTYPE DHT22           // DHT 22  (AM2302)
// #define DHTTYPE DHT21        // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 4 to 10K resistor from pin 2 (data) to pin 1 (power) of the dht

DHT dht(DHTPIN, DHTTYPE);        // DHT Object initialisieren

void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
  dht.begin();                    // Object bzw. Sensor initialisieren
}

void loop() {
  float h = dht.readHumidity();        // Reading temperature
  float t = dht.readTemperature();     // or humidity takes about 250ms to 2s
  if (isnan(t) || isnan(h))
  {          // check if h, t are valid, if NaN (not a number) then something wrong!
    Serial.println("Failed to read from DHT");
  }  // if
  else
  {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }  // else
}  // loop
