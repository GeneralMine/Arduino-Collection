/* Uses I2C port to drive a bar graph
 * Turns on a series of LEDs proportional to a value of an analog sensor. */

#include <Wire.h>

const int address = 0x38;                            // Adresse fuer PCF8574 
const int maxLEDs = 8;                               // Anzahl LEDs 

const int analogInPin = 0;                           // Analog Eingangspin verbunden mit Poti

int sensorValue = 0;                                 // Wert vom Poti
int ledLevel = 0;                                    // Poti Wert in LED Level umwandeln
int ledBits = 0;                                     // bits fuer jede LED auf 0 (aus) oder 1 (ein)

void setup()
{
  Wire.begin();                                      // I2C Bus initialisieren
}

void loop()
{
  sensorValue = analogRead(analogInPin);             // analog Wert einlesen
  ledLevel = map(sensorValue, 0, 1000, 0, maxLEDs);  // in Anzahl LEDs "mapen"
  for (int led = 0; led < maxLEDs; led++)
  {
    if (led < ledLevel)
    {
      bitWrite(ledBits,led, HIGH);                   // LED einschalten wenn kleiner Level
    }
    else
    {
      bitWrite(ledBits,led, LOW);                    // LED ausschalten wenn groeßer Level
    }
  }  
  // send the value to I2C
  Wire.beginTransmission(address);                   // Byte an I2C Expander senden
  Wire.write(ledBits);
  Wire.endTransmission();
  delay(300);
}
