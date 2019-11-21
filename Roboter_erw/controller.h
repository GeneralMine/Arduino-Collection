#include "Arduino.h"

class Controller
{
  private:
  
  int pinX;
  int pinY;
  int pinButton;
  
  int steps;
  
  int posX;
  int posY;
  int relPosX;
  int relPosY;
  
  public:
  
  Controller(int X, int Y, int Button, int Steps)  {
    pinX = X;
    pinY = Y;
    pinButton = Button;
    steps = Steps/2;
  }
  
 
 
  float ValueX()  {
    relPosX = analogRead(pinX) - steps;
    return(relPosX/(steps/100));
  }
  
  float ValueY()  {
    relPosY = analogRead(pinY) - steps;
    return(relPosY/(steps/100));
  }
};
