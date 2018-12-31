
time_t requestSync()
{
  // Serial.write(TIME_REQUEST);  
  return 0; // the time will be sent later in response to serial mesg
}

void processSyncMessage()
{
  // if time sync available from serial port, update time and return true
  while(Serial.available() >=  TIME_MSG_LEN)  // time message consists of a header and ten ascii digits
  {
    char c = Serial.read() ; 
    Serial.print(c);  
    if( c == TIME_HEADER )
    {       
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN -1; i++)
      {   
        c = Serial.read();          
        if( c >= '0' && c <= '9'){   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number    
        }
      }  // for  
      setTime(pctime);   // Sync Arduino clock to the time received on the serial port
    }  // if  
  }  // while
}  // fct

