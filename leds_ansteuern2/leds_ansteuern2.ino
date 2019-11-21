#define MaxT 4
#define PULLUP 1
#define toggeln 1

int LEDArray[] = {2,3,4,5};
int TArray[] = {6,7,8,9};
int TStat[MaxT];
int TStatOld[MaxT];
int LEDStat[MaxT];
void setup()
{
  for(int i=0;i<=MaxT;i++)
  {
    pinMode(LEDArray[i], OUTPUT);
    pinMode(TArray[i], INPUT);
    if (PULLUP == 1)
      digitalWrite(TArray[i],HIGH);
    else
      digitalWrite(TArray[i],LOW);
  }
}


void loop()
{
  if(toggeln == 0)
  {
    for(int i=0;i<MaxT;i++)
    {
      TStat[i] = TStats(i);
      if (TStat != TStatOld)
        digitalWrite(TArray[i],TStat[i]);
      TStat[i] = TStatOld[i];
    }
  }
  else
    toggelnf(); 
}





