class Fahrzeug
{
  float speed1;
  float speed2;
  
  int m1e;
  int m1v;
  int m1b;
  int m2e;
  int m2v;
  int m2b;
  
  public:
  
  Fahrzeug(int M1e, int M1v, int M1b, int M2e, int M2v, int M2b)  {
    m1e = M1e;
    m1v = M1v;
    m1b = M1b;
    m2e = M2e;
    m2v = M2v;
    m2b = M2b;
  }
  
  void setSpeed1()  {
    float vx = con1.ValueX();
    float vy = con1.ValueY();
    if(vx > 0)  {
      speed1 = 128/(vy/100);
    }
    else  {
      speed1 = (128/(vy/100))/(vx/100);
    
    }
  }
  
  void setSpeed2()  {
    float vx = con1.ValueX();
    float vy = con1.ValueY();
    if(vx < 0)  {
      speed2 = 124/(vy/100);
    }
    else  {
      speed2 = (124/(vy/100))/(vx/100); 
    }
  }
  
  
  
  void drive()  {
    setSpeed1();
    setSpeed2();
    if(speed1||speed2 > 0)  {
      digitalWrite(m1v, 1);
      digitalWrite(m1b, 0);
      digitalWrite(m2v, 1);
      digitalWrite(m2b, 0);
    }
    else  {
      digitalWrite(m1b, 1);
      digitalWrite(m1v, 0);
      digitalWrite(m2b, 1);
      digitalWrite(m2v, 0);
    }
    analogWrite(m1e, speed1);
    analogWrite(m2e, speed2);
  }
};
