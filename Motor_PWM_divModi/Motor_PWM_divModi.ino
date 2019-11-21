/* SW steuert einen Motor in beide Richtungen über zwei Kanäle
einer davon als PWM, damit wird auch Geschwindigkeit geregelt */

int motorPin1=2;
int motorPin2=3;                  // PWM

void setup(){
  pinMode(motorPin1, OUTPUT);    // Pin als Ausgang
  pinMode(motorPin2, OUTPUT);    // Pin als Ausgang
} 

void motorStop(){
  digitalWrite(motorPin1,LOW);  // Beide Pns auf LOW
  digitalWrite(motorPin2,LOW);  // dann ist Motor aus
  delay(1000);
} 

void loop(){
  motorStop();                    // Motor Stop
  digitalWrite(motorPin1, HIGH);  // Motor Vor
  digitalWrite(motorPin2, LOW);
  delay(1000);
  motorStop();                    // Motor Stop
  digitalWrite(motorPin1, LOW);   // Motor Rueck
  digitalWrite(motorPin2, HIGH);
  delay(1000);
  motorStop();                    // Motor Stop
  
  digitalWrite(motorPin1, LOW);   // Motor Vor, langsam zu schnell
  for (int i=0; i<255; i++){
    analogWrite(motorPin2, i);
    delay(50);
  }
  motorStop();                    // Motor Stop
  digitalWrite(motorPin1, HIGH);  // Motor Rueck, langsam zu schnell
  for (int i=255; i>0; i--){
    analogWrite(motorPin2, i);
    delay(50);
  }
  motorStop();                    // Motor Stop
  digitalWrite(motorPin1, LOW);   // Motor Vor, schnell zu langsam
  for (int i=255; i>0; i--){
    analogWrite(motorPin2, i);
    delay(50);
  }
  motorStop();                    // Motor Stop
  digitalWrite(motorPin1, HIGH);  // Motor Rueck, schnell zu langsam
  for (int i=0; i<255; i++){
    analogWrite(motorPin2, i);
    delay(50);
  }
  motorStop();                    // Motor Stop
}

