/*  LED bar graph
  Schaltet eine Reihe von LEDs abhängig von der Stellung (Wert) eines
  Potentiometers ein und aus. -->  Balkenanzeige
  Der Schaltkreis:  LEDs von Pin 2 bis Pin 11 gegen Masse   */

// diese Constanten ändern sich nicht:
const int analogPin = A0;     // der Pin mit dem das Potentiometer verbunden ist
const int ledAnzahl = 10;     // Anzahl der LEDs im bar graph

int ledPins[] = { 
  2, 3, 4, 5, 6, 7,8,9,10,11 };   // ein array mit Pin-Nummmern für LEDs Anschluss

void setup()
{
  // mit dieser for Schleife werden alle LED pins aus dem Array als Ausgang gesetzt
  for (int i = 0; i < ledAnzahl; i++)
  {
    pinMode(ledPins[i], OUTPUT); 
  }
}

void loop()
{
  int sensorWert = analogRead(analogPin);                  // Wert des Potentiometer lesen
  int ledLevel = map(sensorWert, 0, 1023, 0, ledAnzahl);   // map "Wert" im Bereich von 0 bis Anzahl LEDs
  // Schleife durchläuft das LED array:
  for (int i = 0; i < ledAnzahl; i++)                      // Schleife durchläuft das LED array:
  {
    if (i < ledLevel)                    // if the array element's index is less than ledLevel,
    {                                    // turn the pin for this element on:
      digitalWrite(ledPins[i], HIGH);
    }     // if
    else                                 // turn off all pins higher than the ledLevel:
    {
      digitalWrite(ledPins[i], LOW);    
    }     // else
  }       // for
}         // loop

