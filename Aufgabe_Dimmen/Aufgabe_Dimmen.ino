/*   Eine LED langsam ein und wieder ausschalten (Dimmen)  */

#define VMAX 50
#define VMAX10 1000

int ledPin = 9;                            // Pin-Nr für LED
int pwm = 0;                               // Wert für PWM für analogWrite 
int delta = 15;                            // Schrittwert 

void setup()
{
  pinMode(ledPin, OUTPUT);                 // LED Pin ais Ausgang
  Serial.begin(9600);
}  //  setup

void loop()                                // Hier die Endlosschleife
{ 
  pwm = constrain(pwm,0,255);
  analogWrite(ledPin, pwm);                // PWM Wert ausgeben
  Serial.println(pwm);
  if (pwm <= 0)                  // Wenn groester  oder kleinster erreicht Richtung ändern
  {
    delta = -delta;                        //  Richtung ändern
    delay(VMAX10);                             // kurz warten, sonst zu schnell
  }  // if
  else
  {
    if (pwm >= 255)                      // Wenn groester  oder kleinster erreicht Richtung ändern
    {
      delta = -delta;                        //  Richtung ändern
      delay(VMAX10);                             // kurz warten, sonst zu schnell
    }  // if
  }  // else
  pwm = pwm + delta;                       // PWM Wert einen Schritt rauf oder runter 
  delay(VMAX);                             // kurz warten, sonst zu schnell
}  // loop

/*
void loop()                                // Hier die Endlosschleife
{ 
  for(int i = 0; i <= 255; i = i + delta)  // Werte von 0 bis 255 ausgeben
    {
    analogWrite(ledPin, i);                // PWM Wert ausgeben    
    delay(VMAX);                           // kurz warten, sonst zu schnell
  }
  for(int i = 255; i >= 0; i = i - delta)  // Werte von2550 bis 0 ausgeben
  {
    analogWrite(ledPin, i);                // PWM Wert ausgeben    
    delay(VMAX);                           // kurz warten, sonst zu schnell
  }
}
*/

