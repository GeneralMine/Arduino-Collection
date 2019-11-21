#define MaxLED 4
#define MaxTaster 4
#define PULLUP 1

int ledPins[] = {2, 3, 4, 5};
int TArray[] = {6, 7, 8, 9};
boolean TStatus;
int stat;

void setup()
{
  for(int i=0; i<MaxLED;i++)
  {
    pinMode(ledPins[i],OUTPUT);
    pinMode(TArray[i],INPUT);
    if(PULLUP == 1)
      digitalWrite(TArray[i],HIGH);
  }
}

void loop()
{
  for(int i=0;i<MaxTaster;i++)
  {
    TStatus = TStat(i);
    digitalWrite(ledPins[i], TStatus);
  }
}
