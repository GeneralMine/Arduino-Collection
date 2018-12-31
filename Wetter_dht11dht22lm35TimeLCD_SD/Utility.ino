
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
  

