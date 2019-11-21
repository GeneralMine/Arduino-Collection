void MotorenSet()                 // setzen der Motor-Steuer-Ausgänge
{
  pinMode(motor1_Pin1, OUTPUT);
  pinMode(motor1_Pin2, OUTPUT);
  pinMode(motor2_Pin1, OUTPUT);
  pinMode(motor2_Pin2, OUTPUT);
}

void MotorenMove(int mV, int pwm1, int pwm2)  // Funktion zum Ansteuern der Motoren
{  
  byte m1_1, m1_2, m2_1, m2_2;

  switch(mV)
  {
    case FORWARD:                 // Forwärts
      m1_1 = LOW; m1_2 = HIGH;    // Setzen der 4 H-Brücken Schalter    
      m2_1 = LOW; m2_2 = HIGH;
      break;
    case BACKWARD:                // Rückwärts
      m1_1 = HIGH; m1_2 = LOW;    // Setzen der 4 H-Brücken Schalter
      m2_1 = HIGH; m2_2 = LOW;
      break;
    case RIGHT:                   // Rechts
      m1_1 = HIGH; m1_2 = LOW;    // Setzen der 4 H-Brücken Schalter
      m2_1 = LOW;  m2_2 = HIGH;
      break;
    case LEFT:                    // Links
      m1_1 = LOW;  m1_2 = HIGH;   // Setzen der 4 H-Brücken Schalter  
      m2_1 = HIGH; m2_2 = LOW;
      break;
    case PAUSE:                   // Pause
      m1_1 = LOW; m1_2 = LOW;     // Setzen der 4 H-Brücken Schalter 
      m2_1 = LOW; m2_2 = LOW;
      break;
    default:                      // bei allen anderen Werten nichts tun
      break;  
  }  // switch
  digitalWrite(motor1_Pin1, m1_1);  // Ansteuern der 4 H-Brücken Schalter
  digitalWrite(motor1_Pin2, m1_2);  // Ansteuern der 4 H-Brücken Schalter
  digitalWrite(motor2_Pin1, m2_1);  // Ansteuern der 4 H-Brücken Schalter
  digitalWrite(motor2_Pin2, m2_2);  // Ansteuern der 4 H-Brücken Schalter
  analogWrite(enableM1Pin, pwm1);    // Ansteuern PWM Motor 1
  analogWrite(enableM2Pin, pwm2);    // Ansteuern PWM Motor 2
}    // fkt

