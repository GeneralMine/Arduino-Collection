boolean TStats(int i)
{
  boolean stats = digitalRead(TArray[i]);
  return(stats);
}

void toggelnf()
{
  for(int i=0;i<=MaxT;i++)
  {
    TStat[i] = TStats(i);
    if(TStatOld[i] == 0 && TStat[i] == 1)
    {
      digitalWrite(LEDArray[i], LEDStat[i]);
      LEDStat[i] = !LEDStat[i];
      TStatOld[i] = TStat[i]; 
    }
  }
}
         
        
        
