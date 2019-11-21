#define MAXARRAY 99
#define MAXLED 4
#define TST_SCHWELLE 800
#define LED_PIN_ROT 2
#define LED_PIN_GRUEN 3
#define LED_PIN_GELB 4
#define LED_PIN_BLAU 5
int ledPin[] = {LED_PIN_ROT, LED_PIN_GRUEN, LED_PIN_GELB, LED_PIN_BLAU};
#define tasterPinRot A1
#define tasterPinGruen A2
#define tasterPinGelb A3
#define tasterPinBlau A4
#define tasterStartStopPin 8
#define tasterResetPin 9

#define ledStatusPinGruen 10
#define ledStatusPinGelb 11
#define ledStatusPinRot 12
#define piezoPin 13

#define counterResetPin 7
#define counterClockPin 6

int analogPin = A5;
int interval = 200;   // Intervalzeit (2 Sekunden)
unsigned long prev;    // Zeit-Variable
int ledStatus = HIGH;  


int colorArray[MAXARRAY];
int tones[] = {1047, 1175, 1319, 1397};
int counter = 0;
int counterMax = 0;
int counterAktuell = 0;
boolean fail = false;
boolean spielStart = false;

void setup() 
{
  Serial.begin(9600);
  
  for (int i=0; i<MAXLED; i++)
    pinMode (ledPin[i], OUTPUT);
    
  pinMode(ledStatusPinGruen, OUTPUT);  
  pinMode(ledStatusPinGelb, OUTPUT);   
  pinMode(ledStatusPinRot, OUTPUT);    
  pinMode(counterResetPin, OUTPUT);   
  pinMode(counterClockPin, OUTPUT);   

  pinMode(tasterResetPin, INPUT);
  digitalWrite(tasterResetPin, HIGH);

  pinMode(tasterStartStopPin,INPUT);
  digitalWrite(tasterStartStopPin, HIGH);    // Gelber Taster
  
  prev = millis();
}

void loop()
{
  Serial.println(" ");
  Serial.println("- Fuer Spielstart Gelbe Taste druecken !!!");
  Serial.println("- Zum anzeigen des Highscore Schwarze Taste druecken");
  Serial.println("- Zum loeschne des Highscore Schwarze Taste fuer 3sec. druecken");
  resetCounter();


    if (!spielStart)
  {
     digitalWrite(ledStatusPinGruen, HIGH); // Toggeln der roten LED
      digitalWrite(ledStatusPinRot, LOW);
      digitalWrite(ledStatusPinGelb, LOW);

    while(!spielStart)
   {
     if (!digitalRead(tasterStartStopPin))
      spielStart = true;
     
     if (!digitalRead(tasterPinRot))
     {
       generateTone(0);
       digitalWrite(ledPin[0],HIGH);
       int Wert = analogRead(analogPin);
       delay(Wert+150);
       digitalWrite(ledPin[0],LOW);
     }
     
     if (!digitalRead(tasterPinGruen))
     {
       generateTone(1);
       digitalWrite(ledPin[1],HIGH);
       int Wert = analogRead(analogPin);
       delay(Wert+150);
       digitalWrite(ledPin[1],LOW);
     }
     
     if (!digitalRead(tasterPinGelb))
     {
       generateTone(2);
       digitalWrite(ledPin[2],HIGH);
       int Wert = analogRead(analogPin);
       delay(Wert+150);
       digitalWrite(ledPin[2],LOW);
     }
     
     if (!digitalRead(tasterPinBlau))
     {
       generateTone(3);
       digitalWrite(ledPin[3],HIGH);
       int Wert = analogRead(analogPin);
       delay(Wert+150);
       digitalWrite(ledPin[3],LOW);
     }
     
     if (!digitalRead(tasterResetPin))
      {
         showZahl(counterMax);
         delay(1500);
         if (!digitalRead(tasterResetPin))
         {
           counterMax = 0;
           counterAktuell = 0;
           showZahl(counterMax);
           delay(1000);
         }
       else
         {
           resetCounter();
           //showZahl(counterAktuell);
         }
       }
     }
    }
   else
  {
    Serial.println("SpielStart");
    delay(500);
    generateColors();
    int tasterCode;
    for(int i = 0; i<=  counter; i++)
    {
      digitalWrite(ledStatusPinRot, LOW);
      digitalWrite(ledStatusPinGelb,HIGH);
      digitalWrite(ledStatusPinGruen, LOW);
      giveSignalSequence(i);
      for(int k = 0; k <=  i; k++)
      {
        digitalWrite(ledStatusPinGelb, LOW);
        while((analogRead(tasterPinRot) > TST_SCHWELLE) && (analogRead(tasterPinGruen) > TST_SCHWELLE) &&
              (analogRead(tasterPinGelb) > TST_SCHWELLE) && (analogRead(tasterPinBlau)) > TST_SCHWELLE);
        //Serial.println("Taste gedrückt!");
        
        
        
        if(analogRead(tasterPinRot) < TST_SCHWELLE)
        {
          tasterCode = 0; 
          Serial.println("richtige Taste gedrückt");
        }
        
        if(analogRead(tasterPinGruen) < TST_SCHWELLE)
        {
          tasterCode = 1;
          Serial.println("richtige Taste gedrückt");
        }
        if(analogRead(tasterPinGelb) < TST_SCHWELLE)
        {
          tasterCode = 2;
          Serial.println("richtige Taste gedrückt");
        }
        if(analogRead(tasterPinBlau) < TST_SCHWELLE)
        {
          tasterCode = 3;
          Serial.println("richtige Taste gedrückt");
        }
        giveSignal(tasterCode);
        if(colorArray[k] != tasterCode)
        {
          fail = true;
          break;
        }
        
      }
      if(!fail)
      {
        digitalWrite(ledStatusPinRot, LOW);
        digitalWrite(ledStatusPinGelb,LOW);
        digitalWrite(ledStatusPinGruen, HIGH);
        Serial.println("richtig");
        
        digitalWrite(counterClockPin, HIGH);
        delay(1);
        digitalWrite(counterClockPin, LOW);
        delay(1);
        //showZahl( counter +1);
        counter+1;
        
        delay(500);
      }
      else
      {
        digitalWrite(ledStatusPinRot, HIGH);
        digitalWrite(ledStatusPinGelb,LOW);
        digitalWrite(ledStatusPinGruen, LOW);
        for (int i = 3000; i>500; i-=150)
        {
          tone(piezoPin, i, 10);
          delay(20);
        }
        Serial.println("falsch");
        showZahl(counter);
        counterAktuell = counter;
        if (counter >  counterMax)
          counterMax=counter;
        counter= 0;
        fail=false;
        spielStart = false;
        delay(2000);
        break;
      }
      delay(300);
      if (counter +1 == MAXARRAY)
      {
        showZahl(counter + 1);
        digitalWrite(ledStatusPinRot, LOW);
        digitalWrite(ledStatusPinGelb,LOW);
        digitalWrite(ledStatusPinGruen, HIGH);
        for(int i = 500; i < 3000; i+= 150)
        {
          tone (piezoPin, i, 10);
          delay(20);
        }
        spielStart = false;
        Serial.println("Ende!");
        delay(2000);
        counter = 0;
        fail= false;
        break;
      }
      counter++;
    }
  }
}

void showZahl(int value)
{
  resetCounter();
  for (int i=0; i< value;i++)
  {
    digitalWrite(counterClockPin, HIGH);
    delay(1);
    digitalWrite(counterClockPin, LOW);
    delay(1);
  }
}

void generateColors()
{
  randomSeed(analogRead(0));
  for(int i=0; i< MAXARRAY; i++)
    colorArray[i] = random(4);
  for(int i=0; i<MAXARRAY; i++)
  {}
    //Serial.println(/*colorArray[i]*/);
}

void giveSignalSequence(int value)
{
  int Wert = analogRead(analogPin);
  int time = map(Wert,0,1023,100,2000);
  
  for(int i = 0; i<=value; i++)
  {
    digitalWrite(2 + colorArray[i], HIGH);
    generateTone(colorArray[i]);
    delay(time);
    digitalWrite(2 + colorArray[i], LOW);
    if (i<value)
    delay(200);
  }
}

void giveSignal(int value)
{
  digitalWrite(2+value, HIGH);
  generateTone(value);
  delay(200);
  digitalWrite(2+value, LOW);
  delay(200);
}

void resetCounter()
{
  digitalWrite(counterResetPin, HIGH);
    delay(2);
    digitalWrite(counterResetPin, LOW);
    delay(1);
}

void generateTone(int value)
{
   int Wert = analogRead(analogPin);
  int time = map(Wert,0,1023,100,2000);
  
  tone(piezoPin, tones[value], time+150);
}
