/* 2 Motoren mit H-Brücke ansteuern */

int motor1_A=2;
int motor1_B=3;
int motor1_Speed=10;
int motor2_A=4;
int motor2_B=5;
int motor2_Speed=9;

int schritt = 50;
int warte = 1000;

void setup(){
  pinMode(motor1_A,OUTPUT);
  pinMode(motor1_B,OUTPUT);
  pinMode(motor2_A,OUTPUT);
  pinMode(motor2_B,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  // motor1
  Serial.println("Motor1 vorwärts:   von 0 auf Max");
  for (int i=0; i<256; i+=5){
    digitalWrite(motor1_A,HIGH);     // A = HIGH and B = LOW means the motor will turn right
    digitalWrite(motor1_B,LOW);
    analogWrite(motor1_Speed,i);     // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);
  Serial.println("Motor1 vorwärts:   von Max auf 0");
  for (int i=255; i>0; i-=5){
    digitalWrite(motor1_A,HIGH);     // A = HIGH and B = LOW means the motor will turn right
    digitalWrite(motor1_B,LOW);
    analogWrite(motor1_Speed,i);     // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);
  // motor2
  Serial.println("Motor2 vorwärts:   von 0 auf Max");
  for (int i=0; i<256; i+=5){
    digitalWrite(motor2_A,HIGH);     // A = HIGH and B = LOW means the motor will turn right
    digitalWrite(motor2_B,LOW);
    analogWrite(motor2_Speed,i);     // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);
  Serial.println("Motor2 vorwärts:   von Max auf 0");
  for (int i=255; i>0; i-=5){
    digitalWrite(motor2_A,HIGH);     // A = HIGH and B = LOW means the motor will turn right
    digitalWrite(motor2_B,LOW);
    analogWrite(motor2_Speed,i);     // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);

  // turn vice versa
  // motor1
  Serial.println("Motor1 rückwärts:   von 0 auf Max");
  for (int i=0; i<256; i+=5){
    digitalWrite(motor1_A,LOW); // A = LOW and B = HIGH means the motor will turn left
    digitalWrite(motor1_B,HIGH);
    analogWrite(motor1_Speed,i); // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);
  Serial.println("Motor1 rückwärts:   von Max auf 0");
  for (int i=255; i>0; i-=5){
    digitalWrite(motor1_A,LOW); // A = LOW and B = HIGH means the motor will turn left
    digitalWrite(motor1_B,HIGH);
    analogWrite(motor1_Speed,i); // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);
  // motor2
  Serial.println("Motor2 rückwärts:   von 0 auf Max");
  for (int i=0; i<256; i+=5){
    digitalWrite(motor2_A,LOW); // A = LOW and B = HIGH means the motor will turn left
    digitalWrite(motor2_B,HIGH);
    analogWrite(motor2_Speed,i); // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);
  Serial.println("Motor1 rückwärts:   von Max auf 0");
  for (int i=255; i>0; i-=5){
    digitalWrite(motor2_A,LOW); // A = LOW and B = HIGH means the motor will turn left
    digitalWrite(motor2_B,HIGH);
    analogWrite(motor2_Speed,i); // speed counts from 0 to 255
    delay(schritt);
  }
  delay(warte);
}

