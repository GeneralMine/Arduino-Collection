/* Farbensequenzspiel */

#define MAXARRAY 6               // Vorgabe der Sequenzlänge
# define MAXLED 4                // Anzahl der LEDs
int ledPin[] = {2, 3, 4, 5};     // LED-Array mit Pin-Werten
#define piezoPin 13              // Piezo-Pin
#define tasterPinRot 6           // Taster Pin an roter LED
#define tasterPinGruen 7         // Taster-Pin an grüner LED
#define tasterPinGelb 8          // Taster-Pin an gelber LED
#define tasterPinWeiss 9         // Taster-Pin an weißer LED
#define ledStatusPinGruen 10     // Status LED grün
#define ledStatusPinGelb 11      // Status LED gelb
#define ledStatusPinRot 12       // Status LED rot

int colorArray[MAXARRAY];        // Enthält die Zahlenfolge für anzuzeigende Farben
int tones[] = {1047, 1175, 1319, 1397}; // Tonfrequenzen für die 4 Farben
int counter = 0;                 // Anzahl der gerade aufleuchtenden LEDs
boolean fail = false;

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < MAXLED; i++)
    pinMode(ledPin[i], OUTPUT);       // LED-Pins als OUTPUT programmieren
  pinMode(tasterPinRot, INPUT);
  digitalWrite(tasterPinRot, HIGH);
  pinMode(tasterPinGruen, INPUT);
  digitalWrite(tasterPinGruen, HIGH);
  pinMode(tasterPinGelb, INPUT);
  digitalWrite(tasterPinGelb, HIGH);
  pinMode(tasterPinWeiss, INPUT);
  digitalWrite(tasterPinWeiss, HIGH);
  pinMode(ledStatusPinGruen, OUTPUT);
  pinMode(ledStatusPinGelb, OUTPUT);
  pinMode(ledStatusPinRot, OUTPUT);
}

void loop()
{
  digitalWrite(ledStatusPinGelb, HIGH);
  Serial.println("Spielstart");
  generateColors();
  int tasterCode;
  for(int i = 0; i <= counter; i++)    // Äußere Schleife
  { 
    digitalWrite(ledStatusPinGelb, HIGH);
    giveSignalSequence(i);
    for(int k = 0; k <= i; k++)        // Innere Schleife
    { 
      digitalWrite(ledStatusPinGelb, LOW);
      while(digitalRead(tasterPinRot) && digitalRead(tasterPinGruen) &&
            digitalRead(tasterPinGelb) && digitalRead(tasterPinWeiss));
      Serial.println("Taste gedrückt!"); // Zur Kontrolle im Serial Monitor
      // Anzeigen der gerückten Farbe
      if(!digitalRead(tasterPinRot))
        tasterCode = 0;
      if(!digitalRead(tasterPinGruen))
        tasterCode = 1;
      if(!digitalRead(tasterPinGelb))
        tasterCode = 2;
      if(!digitalRead(tasterPinWeiss))
        tasterCode = 3;
      giveSignal(tasterCode);
      // Überprüfung ob richtige Farbe gedrückt wurde
      if(colorArray[k] != tasterCode)
      {
        fail = true;
        break; // Innere for-Schleife verlassen
      }  // if
    }    // innere for
    if(!fail)
      Serial.println("richtig"); // Zur Kontrolle im Serial Monitor
    else
    {
      digitalWrite(ledStatusPinRot, HIGH);
      for(int i = 3000; i > 500; i-=150)
      {
        tone(piezoPin, i, 10); delay(20);
      }  // for
      Serial.println("falsch"); // Zur Kontrolle im Serial Monitor
      delay(2000);
      digitalWrite(ledStatusPinRot, LOW);
      counter = 0; fail = false;
      break;      // for-Schleife verlassen
    }  // else
    delay(2000);
    if(counter + 1 == MAXARRAY)
    {
      digitalWrite(ledStatusPinGruen, HIGH);
      for(int i = 500; i < 3000; i+=150)
      {
        tone(piezoPin, i, 10); delay(20);
      }  // for
      Serial.println("Ende!"); // Zur Kontrolle im Serial Monitor
      delay(2000);
      digitalWrite(ledStatusPinGruen, LOW);
      counter = 0; fail = false;
      break;                   // Äußere for-Schleife verlassen
    }  // if
    counter++; // Zähler inkrementieren
  }  // for
}    // loop

void giveSignalSequence(int value)      // Anzeige LEDs
{
  for(int i = 0; i <= value; i++)
  {
    digitalWrite(2 + colorArray[i], HIGH);
    generateTone(colorArray[i]);
    delay(1000);
    digitalWrite(2 + colorArray[i], LOW);
    if (i < value)
      delay(1000);
  }
}

void generateTone(int value)
{
  tone(piezoPin, tones[value], 1000);
}

void giveSignal(int value)    // Anzeige LED + Tonsignal
{
  digitalWrite(2 + value, HIGH);
  generateTone(value);
  delay(200);
  digitalWrite(2 + value, LOW);
  delay(200);
}

void generateColors()
{
  randomSeed(analogRead(0));
  for(int i = 0; i < MAXARRAY; i++)
    colorArray[i] = random(4); // Zufallszahlen von 0 bis 3 generieren
  // 0 = Rot, 1 = Grün, 2 = Gelb, 3 = Weiss
  for(int i = 0; i < MAXARRAY; i++)
    Serial.println(colorArray[i]); // Zur Kontrolle im Serial Monitor
}

