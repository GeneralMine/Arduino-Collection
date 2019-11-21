/*  LED bar graph
  Schaltet eine Reihe von LEDs abhängig von der Helligkeit (Wert) eines
  Lichtsensors ein und aus. -->  Balkenanzeige  und zeigt Wert im seriellen Monitor an  */

int ledAnzahl = 10;           // Anzahl der LEDs im bar graph
int analogPin = A0;            // Pin mit dem Potentiometer verbunden ist
int analogLichtWert = 0;  
int interval = 2000;          // Intervallzeit (2 Sekunden)
int zeilenZaehler = 1;
unsigned long prev;           // Zeit-Variable

int ledPins[] = {2,3,4,5,6,7,8,9,10,11 };   // ein array mit Pin-Nummmern für LEDs Anschluss

void setup()
{
  // mit dieser for Schleife werden alle LED pins aus dem Array als Ausgang gesetzt
  for (int i = 0; i < ledAnzahl; i++)
  {
    pinMode(ledPins[i], OUTPUT);    // 10 ledPins als Ausgänge einstellen
    Serial.begin(9600);             // serielle Schnittstelle konfigurieren
    prev = millis();                // jetzigen Zeitstempel merken
  }  // for
}    // setup()

void loop()
{
  analogLichtWert = analogRead(analogPin);  // Wert des Lichtsensors lesen
  steuereLEDs(analogLichtWert);             // Wert nur alle "interval" ms ausgeben 
  if((millis() - prev) > interval)          
  {
    prev = millis();                        // jetzigen Zeitstempel wieder merken (quasi reset)
    Serial.print("Zeile  ");                // Print ohne new line (LN)
    Serial.print(zeilenZaehler);
    Serial.print("  : ");
    zeilenZaehler++;
    Serial.println(analogLichtWert);        // zum Schluß der Zeile "print" mit new line (LN)
  }  // if
}    // loop()
  
// Funktion zum Ansteuern der LED's
void steuereLEDs(int wert)        
{
  int ledLevel = map(wert, 0, 1023, 0, (ledAnzahl-1));   // map result to a range from 0 to number of LEDs
  for (int i = 0; i < ledAnzahl; i++)                    // Schleife durchläuft das LED array:
  {
    if (i < ledLevel)                // if the array element's index is less than ledLevel,
    {                                // turn the pin for this element on:
      digitalWrite(ledPins[i], LOW);
    }     // if
    else                             // turn off all pins higher than the ledLevel:
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
}    // fkt
