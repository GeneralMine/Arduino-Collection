/*
  LED Lauflicht
  Schaltet eine Reihe von LEDs nach einem bestimmten Muster ein und aus 

  Im Schaltkreis sind 10 LEDs mit einem Widerstand gegen Masse geschaltet   
 */

// diese Constante ändert sich nicht:
const int ledAnzahl = 10;      // Anzahl der LEDs im bar graph
const int demoDauer = 4;      // Anzahl der Demos, bevor gewechselt wird

int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};     // ein array mit Pin-Nummmern für LED Anschluss
int wartezeit = 200;                              // Pause zwischen den Wechseln in ms

void setup()
{
  // mit dieser for Schleife werden alle LED pins aus dem Array als Ausgang gesetzt
  for (int i = 0; i < ledAnzahl; i++)
  {
    pinMode(ledPins[i], OUTPUT);                  // alle Pins des Arrays als Ausgang
  }
}

void loop()
{
  for (int i = 0; i < demoDauer; i++)             // Jede Programmvariante mehrfach durchlaufen
  {
    // Schleife, die das LED array durchläuft:
    for (int i = 0; i < ledAnzahl; i++)           // Lauflicht vorwärts 
    {
      digitalWrite(ledPins[i], HIGH);             // Array Element "i" auf HIGH Pegel
      delay(wartezeit);                           // kurz leuchten lassen, sonst sieht man nichts 
      digitalWrite(ledPins[i], LOW);              // Array Element "i" auf LOW Pegel  
    }   // for
  }     // for

  for (int i = 0; i < demoDauer; i++)             // Jede Programmvariante mehrfach durchlaufen     
  { 
    for (int i = ledAnzahl-1; i > -1; i--)        // Lauflicht rückwärts
    {
      digitalWrite(ledPins[i], HIGH);             // Array Element "i" auf HIGH Pegel
      delay(wartezeit);
      digitalWrite(ledPins[i], LOW);              // Array Element "i" auf LOW Pegel  
    }  // for
  }    // for

  for (int i = 0; i < demoDauer; i++)              // Jede Programmvariante mehrfach durchlaufen
  {
    for (int i = 0; i < ledAnzahl; i++)            // Lauflicht vorwärts und rückwärts 
    {
      digitalWrite(ledPins[i], HIGH);              // Array Elemente von vorne auf HIGH Pegel
      digitalWrite(ledPins[(ledAnzahl-1)-i], HIGH); // Array Element von hinten auf HIGH Pegel
      delay(wartezeit);
      digitalWrite(ledPins[i], LOW);               // Array Element von vorne auf LOW Pegel  
      digitalWrite(ledPins[(ledAnzahl-1)-i], LOW); // Array Element von hinten auf LOW Pegel  
    }  // for 
  }    // for 

  for (int i = 0; i < (8*demoDauer); i++)         
  {                                                // Lauflicht mit Zufallszahl  
    int zufall;
    zufall = random(ledAnzahl);                    // liefert Zufallszahl zwischen 0 & < "ledCount"
    digitalWrite(ledPins[zufall], HIGH);           // Array Element "i" auf HIGH Pegel
    delay(wartezeit);
    digitalWrite(ledPins[zufall], LOW);            // Array Element "i" auf LOW Pegel  
  }  // for
  delay(1000);          // kurze Pause und von vorne
}    // loop

