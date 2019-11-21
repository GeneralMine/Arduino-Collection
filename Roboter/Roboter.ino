#include "RoboAchse.h"

RoboAchse robo1(3,5,8,9,10,11);



void setup()
{
  robo1.setMode(1);
  robo1.setPower1(255);
  robo1.setPower2(255);
  robo1.fahren();
}

void loop()
{
  
}
