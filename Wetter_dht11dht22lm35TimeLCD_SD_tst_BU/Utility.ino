
void decodeBefehl()
{
  char c = Serial.read(); 
  Serial.println(c);
  while(Serial.available())   
  {
    c = Serial.read(); 
    Serial.println(c);  
    switch (c)
    {
      case 'P':
      {
        long corrTime = readSerialNumber();
        Serial.println(corrTime);
        adjustTime(corrTime);
        break;
      }  // case
      case 'M':
      {
        long corrTime = readSerialNumber();
        corrTime = corrTime * -1;
        Serial.println(corrTime);
        adjustTime(corrTime);
        break;
      }  // case
      case 'R':
      {
        if (!sdRead())
        {
          Serial.print("Reading File:  ");
          Serial.print(myFileName);
          Serial.println("  nicht erfolgreich");
        }  // if    
        break;
      }  // case
      case 'D':
      {
        if (SD.remove(myFileName) )
        {
          Serial.print("Deleting File:  ");
          Serial.print(myFileName);
          Serial.println("   erfolgreich");
        }  // if
        else
        {
          Serial.print("Deleting File:  ");
          Serial.print(myFileName);
          Serial.println("   nicht erfolgreich");
        }  // if
        break;
      }  // case            
      default:
        break;
    }  // switch      
  }  // while
}  // fct  

long readSerialNumber()
{
  long zahl = 0;
  while(Serial.available())  // solange Zeichen vorhanden diese lesen
  {
    char c = Serial.read() ; 
//    Serial.print(c);  
    if( c >= '0' && c <= '9')
    {   
      zahl = (10 * zahl) + (c - '0') ; // convert digits to a number    
    }
  }  // while
  return (zahl);
}  // fct
  

