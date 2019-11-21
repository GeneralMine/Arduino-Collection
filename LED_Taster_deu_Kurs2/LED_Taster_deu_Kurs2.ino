const int ledPin = 13;    
const int tasterPin = 2;  
int tasterStatus; 
int tasterStatusOld;
int ledcontrol = LOW;       
void setup()
{                
  pinMode(ledPin, OUTPUT);      
  pinMode(tasterPin, INPUT);   
  Serial.begin(9600);
}

void loop()
{
  tasterStatus = digitalRead(tasterPin);
  if ((tasterStatus == HIGH)&& (tasterStatusOld == LOW))
  {
    ledcontrol = !ledcontrol;
    digitalWrite(ledPin, ledcontrol);
  }
  tasterStatusOld = tasterStatus;
}

