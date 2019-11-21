class Motor
{
  public:
  
  byte p1;
  byte p2;
  
  byte a1;

  Motor(byte pin1, byte pin2, byte analog1):p1(pin1),p2(pin2),a1(analog1)
  {
   // p1 = pin1;
    //p2 = pin2;
    //a1 = analog1;
  }  
  
  public:
  void Motor_vor(byte ges)
  {
    digitalWrite(p1, HIGH);
    analogWrite(a1, ges);
    //delay(time);
    //digitalWrite(p1, LOW);  
  }
  
  void Motor_zur(byte ges)
  {
    digitalWrite(p2, HIGH);
    analogWrite(a1, ges);
    //delay(time);
    //digitalWrite(p2, LOW);  
  }
  
  void Motor_stop()
  {
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    //digitalWrite();  
  }
};
