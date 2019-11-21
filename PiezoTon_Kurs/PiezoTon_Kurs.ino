/*  Referenz:     http://arduino.cc/en/Reference/PinMode
              http://arduino.cc/en/Reference/Constants
              http://arduino.cc/en/Reference/DigitalWrite
              http://arduino.cc/en/Reference/DelayMicroseconds  */
              
#define piezoPin 13              // Piezo-Element an Pin 13
#define DELAY 1200

void setup()
{
  pinMode(piezoPin, OUTPUT);     // Piezo Pin als Ausgang programmieren
}

void loop()
{
  digitalWrite(piezoPin, HIGH);  // Piezo Pin einschalten
  delayMicroseconds(DELAY);      // "DELAY" Microsekunden warten
  digitalWrite(piezoPin, LOW);   // Piezo Pin ausschalten
  delayMicroseconds(DELAY);      // "DELAY" Microsekunden warten
}
