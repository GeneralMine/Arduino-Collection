/*   LED bar graph
  Schaltet eine Reihe von LEDs abhängig von der Helligkeit (Wert) eines
  Lichtsensors ein und aus. -->  Balkenanzeige   */

int ledAnzahl = 10;               // Anzahl der LEDs im bar graph
int analogPin = 0;                // der Pin mit dem das Potentiometer verbunden ist
int analogLichtWert = 0;  
int ledPins[] = {2, 3, 4, 5, 6, 7,8,9,10,11 };  // Array mit Pin-Nummmern für LEDs 

void setup()
{      // mit dieser for Schleife werden alle LED pins aus dem Array als Ausgang gesetzt
  for (int i = 0; i < ledAnzahl; i++)
  {
    pinMode(ledPins[i], OUTPUT); 
  }
}

void loop()
{
  analogLichtWert = analogRead(analogPin);               // Wert des Lichtsensors lesen
  steuereLEDs(analogLichtWert);
}      // loop
  
void steuereLEDs(int wert)                               // Funktion zum Ansteuern der LED's  
{
  int ledLevel = map(wert, 0, 1023, 0, (ledAnzahl-1));   // map "wert" in einen Bereich von 0 bis Anzahl LEDs
  for (int i = 0; i < ledAnzahl; i++)                    // Schleife durchläuft das LED array:
  {
    if (i < ledLevel)                    // if the array element's index is less than ledLevel,
    {                                    // turn the pin for this element on:
      digitalWrite(ledPins[i], LOW);
    }     // if
    else                                 // turn off all pins higher than the ledLevel:
    {
      digitalWrite(ledPins[i], HIGH);    
    }     // else
  }       // for
}         // fkt

// Funktion zum Ansteuern der LED's  KURZFORM
void steuereLEDs2(int wert)        
{
  int ledLevel = map(wert, 0, 1023, 0, (ledAnzahl-1));   // map result to a range from 0 to number of LEDs
  for (int i = 0; i < ledAnzahl; i++)                    // Schleife durchläuft das LED array:
    digitalWrite(ledPins[i], (ledLevel >= i)?HIGH:LOW);
}         // fkt
