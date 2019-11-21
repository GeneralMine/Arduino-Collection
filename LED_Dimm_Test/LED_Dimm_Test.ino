/* 
 */

int ledPin = 7;    // LED connected to digital pin 9
#define DIM_STEP 50
#define DIM_STEP_TIME 600


void setup()
{ 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
} 

void loop()
{              // 0 bis MAX 
  for(int dimWert = 0; dimWert <= 255; dimWert +=DIM_STEP) 
  { 
    analogWrite(ledPin, dimWert);
    Serial.println(dimWert);    
    delay(DIM_STEP_TIME);                            
  } 
  delay(500);
  for(int dimWert = 255; dimWert >= 0; dimWert -=DIM_STEP)
  { 
    //       Von MAX   bis 0
    analogWrite(ledPin, dimWert);         
    Serial.println(dimWert);    
    delay(DIM_STEP_TIME);                            
  } 
  delay(500);
}


