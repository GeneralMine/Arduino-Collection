//#include "Fahrzeug.h"
#include "controller.h"
//#include "Interface.h"


Controller con1(A0, A1, 7, 1023);
//Fahrzeug f1(8,9,10,11,12,13);

#include "Fahrzeug.h"
Fahrzeug f1(8,9,10,11,12,13);

void setup() {
  // put your setup code here, to run once:
  DDRB = 0b11111111;

}

void loop() {
  // put your main code here, to run repeatedly:
  f1.drive();

}
