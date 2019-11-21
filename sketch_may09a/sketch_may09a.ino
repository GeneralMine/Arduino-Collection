#include "TimerOne.h"
#define ANZEIGE_ZEIT 1000

int ledpin = 7;
long millisek = 200;
volatile int ISRCounter = 0;
int ISRCounterOld = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  Timer1.initialize(millisek *1000);
  Timer1.attachInterrupt(blinken);
}

void blinken(){
  ISRCounter++;
  digitalWrite(ledpin, digitalRead(ledpin) ^ 1);
}
void loop() {
  // put your main code here, to run repeatedly:
  if ( ISRCounter != ISRCounterOld)
  {
   Serial.println(ISRCounter); 
   ISRCounterOld = ISRCounter;
 }
 delay(ANZEIGE_ZEIT);
}
