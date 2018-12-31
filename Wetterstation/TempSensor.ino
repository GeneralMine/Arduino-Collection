float Read_Temp()
{
  float result = 0;
  for(int i = 0; i < cycles; i++)
  {  
    float Temperature = (5.0*100.0*analogRead(analogPin))/1024;
    result += Temperature;
    //delay(DELAY);
  }
  
  result /= cycles;
  return(result);
}
