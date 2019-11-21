#include <Arduino.h>

class RoboAchse
{
  private:
  
    byte mode;
    byte steuer;
    
    struct motor
    {
      byte vor;
      byte rueck;
      byte power;
      byte steuer;
    };
    
    motor M1;
    motor M2;
    
    
  public:
  
  RoboAchse(int steuer, int steuer2, int vor, int rueck, int vor2, int rueck2)
  {
    M1.steuer = steuer;
    M2.steuer = steuer2;
    
    M1.power = 0;
    M2.power = 0;
    
    M1.vor = vor;
    M1.rueck = rueck;
    
    M2.vor = vor2;
    M2.rueck = rueck2;
    
    pinMode(steuer, OUTPUT);
    pinMode(vor, OUTPUT);
    pinMode(rueck, OUTPUT);
    pinMode(vor2, OUTPUT);
    pinMode(rueck2, OUTPUT);
    
  }
  
    
    void setMode(byte model)
    {
      mode = constrain(model, 0, 5);
    }
    
    void setPower1(int power)
    {
      M1.power = constrain(power,0, 255);
    }
    
    void setPower2(int power)
    {
      M2.power = constrain(power, 0, 255);
    }
    
    void fahren()
    {
      switch(mode)
        case 1:
          digitalWrite(M1.vor, HIGH);
          digitalWrite(M2.vor, HIGH);
          analogWrite(M1.steuer, M1.power);
          analogWrite(M2.steuer, M2.power);
    }
    
};
