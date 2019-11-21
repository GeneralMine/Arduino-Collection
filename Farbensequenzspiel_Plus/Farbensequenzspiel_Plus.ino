/* Farbensequenzspiel PLUS mit Anzeige und Reset*/

#define MAXARRAY 15              // Vorgabe der Sequenzlänge
#define MAXLED 4                 // Anzahl der LEDs
#define TST_SCHWELLE 800         // Analoge Taster Schwelle 
// 0 = Rot, 1 = Grün, 2 = Gelb, 3 = Blau
#define LED_PIN_ROT 2
#define LED_PIN_GRUEN 3
#define LED_PIN_GELB 4
#define LED_PIN_BLAU 5
int ledPin[] = {LED_PIN_ROT, LED_PIN_GRUEN, LED_PIN_GELB, LED_PIN_BLAU}; // LED-Array mit Pin-Werten
#define tasterPinRot A1          // Taster Pin an roter LED
#define tasterPinGruen A2        // Taster-Pin an grüner LED
#define tasterPinGelb A3         // Taster-Pin an gelber LED
#define tasterPinBlau A4         // Taster-Pin an blau LED
#define tasterStartStopPin 8     // Start Stop Taster-Pin
#define tasterResetPin 9         // Reset Taster-Pin

#define ledStatusPinGruen 10     // Status LED grün
#define ledStatusPinGelb 11      // Status LED gelb
#define ledStatusPinRot 12       // Status LED rot
#define piezoPin 13              // Piezo-Pin

#define counterResetPin 7        // Counter 4026 Reset-Pin #15
#define counterClockPin 6        // Counter 4026 Clock-Pin #1 

int colorArray[MAXARRAY];        // Enthält die Zahlenfolge für anzuzeigende Farben
int tones[] = {1047, 1175, 1319, 1397}; // Tonfrequenzen für die 4 Farben
int counter = 0;                 // Anzahl der gerade aufleuchtenden LEDs
int counterMax = 0;              // HighScore
int counterAktuell = 0;          // Aktuelle Score
boolean fail = false;
boolean spielStart = false;


void setup()
{
  Serial.begin(9600);
  
  for(int i = 0; i < MAXLED; i++)
    pinMode(ledPin[i], OUTPUT);          // LED-Pins als OUTPUT programmieren
  
  pinMode(ledStatusPinGruen, OUTPUT);    // Pin als Ausgang
  pinMode(ledStatusPinGelb, OUTPUT);
  pinMode(ledStatusPinRot, OUTPUT);
  pinMode(counterResetPin, OUTPUT);      // Pin als Ausgang
  pinMode(counterClockPin, OUTPUT);      // Pin als Ausgang
  
  pinMode(tasterResetPin, INPUT);        // Pin als Eingang   
  digitalWrite(tasterResetPin, HIGH);    // Pull Up einschalten
  
  pinMode(tasterStartStopPin, INPUT);      // Pin als Eingang
  digitalWrite(tasterStartStopPin, HIGH);  // Pull Up einschalten
}

void loop()
{
  if (!spielStart)      // Spielbeginn auf Tastendruck
  {                     // Spiel noch nicht begonnen 
    digitalWrite(ledStatusPinRot, LOW);
    digitalWrite(ledStatusPinGelb, LOW);
    digitalWrite(ledStatusPinGruen, HIGH);
    while(!spielStart)  // Tasten abfragen, bis Spiel Start  
    {
      if (!digitalRead(tasterStartStopPin))    // Start-Spiel Taste gedrückt
        spielStart = true;                     // Spiel starten 
      if (!digitalRead(tasterResetPin))        // Reset Taste gedrückt
      {
        showZahl(counterMax);                  // Zeige High Score
        delay(1500);
        if (!digitalRead(tasterResetPin))      // Reset nach 1,5sec immer noch gedrückt dann Reset
        {
          counterMax = 0;
          counterAktuell = 0;
          showZahl(counterMax);
          delay(1000);
        }
        else
        {
          showZahl(counterAktuell);            // Aktuelle Score wieder anzeigen
        }
      }  // if
    }  //while      
  } // if
  else
  {
    Serial.println("Spielstart");
    generateColors();
    int tasterCode;
    for(int i = 0; i <= counter; i++)    // Äußere Schleife
    { 
      digitalWrite(ledStatusPinRot, LOW);
      digitalWrite(ledStatusPinGelb, HIGH);
      digitalWrite(ledStatusPinGruen, LOW);
      giveSignalSequence(i);
      for(int k = 0; k <= i; k++)        // Innere Schleife
      { 
        digitalWrite(ledStatusPinGelb, LOW);
        // Taster mit PULL-UP
        while((analogRead(tasterPinRot) > TST_SCHWELLE) && (analogRead(tasterPinGruen) > TST_SCHWELLE) &&
              (analogRead(tasterPinGelb) > TST_SCHWELLE) && (analogRead(tasterPinBlau)) > TST_SCHWELLE);
        Serial.println("Taste gedrückt!"); // Zur Kontrolle im Serial Monitor
        // Anzeigen der gerückten Farbe
        if(analogRead(tasterPinRot) < TST_SCHWELLE)
          tasterCode = 0;
        if(analogRead(tasterPinGruen) < TST_SCHWELLE)
          tasterCode = 1;
        if(analogRead(tasterPinGelb) < TST_SCHWELLE)
          tasterCode = 2;
        if(analogRead(tasterPinBlau) < TST_SCHWELLE)
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
      {
        digitalWrite(ledStatusPinRot, LOW);
        digitalWrite(ledStatusPinGelb, LOW);
        digitalWrite(ledStatusPinGruen, HIGH);
        Serial.println("richtig");                           // Zur Kontrolle im Serial Monitor
        delay(500);
      }  
      else
      {
        digitalWrite(ledStatusPinRot, HIGH);
        digitalWrite(ledStatusPinGelb, LOW);
        digitalWrite(ledStatusPinGruen, LOW);
        for(int i = 3000; i > 500; i-=150)
        {
          tone(piezoPin, i, 10); delay(20);
        }  // for
        Serial.println("falsch"); // Zur Kontrolle im Serial Monitor
        showZahl(counter);
        counterAktuell = counter;
        if (counter > counterMax)
          counterMax = counter;
        counter = 0; fail = false;
        spielStart = false;
        delay(2000);
        break;      // for-Schleife verlassen
      }  // else
      delay(2000);
      if(counter + 1 == MAXARRAY)
      {
        showZahl(counter + 1);
        digitalWrite(ledStatusPinRot, LOW);
        digitalWrite(ledStatusPinGelb, LOW);
        digitalWrite(ledStatusPinGruen, HIGH);
        for(int i = 500; i < 3000; i+=150)
        {
          tone(piezoPin, i, 10); delay(20);
        }  // for
        spielStart = false;
        Serial.println("Ende!"); // Zur Kontrolle im Serial Monitor
        delay(2000);
        counter = 0; fail = false;
        break;                   // Äußere for-Schleife verlassen
      }  // if
      counter++; // Zähler inkrementieren
    }  // for
  } // else 
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
  // 0 = Rot, 1 = Grün, 2 = Gelb, 3 = Blau
  for(int i = 0; i < MAXARRAY; i++)
    Serial.println(colorArray[i]); // Zur Kontrolle im Serial Monitor
}

