class Motor;
//void Motor::Motor_vor(byte);
byte p1m1 = 8;
byte p2m1 = 9;
byte a1m1 = 6;

byte p1m2 = 10;
byte p2m2 = 11;
byte a1m2 = 5;

//class Motor;

Motor M1(byte p1m1,byte p2m1,byte a1m1);
Motor M2(byte p1m2,byte p2m2,byte a1m2);

void setup() 
{
  for(int i = 0;i < 7;i++)
  {
    digitalWrite(i+5, OUTPUT);  
  }
  
 // M1.Motor(p1m1, p2m1, a1m1);
 // M2.Motor(p1m2, p2m2, a1m2);
}

void loop() 
{
  M1.Motor_vor(253);
 // M2.Motor_vor(254);
}


