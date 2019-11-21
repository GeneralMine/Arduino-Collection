// Bsp erzeugt ein PWM signal mit variabler Frequenz und variablem Tastverhältnis. 
// Arduino's analogWrite() gives you PWM output, but no control over the 
// carrier frequency. The default frequency is low, typically 490 or 
// 3920 Hz. Hier wird gezeigt wie man beides ändern kann
#include <TimerOne.h> 

#define  REPEAT_TIME  2000          // Wartezeit für erneuter Programm Start
#define  DUTYCYCLE_LOOP_TIME  500   // Wartezeit für PWM Duty Cycle Schleife 

const int LedPin = 9;               // PWM Pin 9 oder 10 beim Arduino
float dutyCycle = 0;                // Gleitkommavariable für Duty Cycle Berechnung
 
void setup(void) 
{ 
  Timer1.initialize(2000000);       // Angabe in MicroSek, 1/Sek = Frequenz  
  Serial.begin(9600);               
}  // setup 
 
void loop(void) 
{ 
  for (dutyCycle = 1.0; dutyCycle < 100.0; dutyCycle++)  // Tastverhältnis von 1-100 hochzählen
  { 
    Serial.print("PWM LED, Duty Cycle = "); 
    Serial.println(dutyCycle); 
    Timer1.pwm(LedPin, (dutyCycle * 1023.0) / 100);      // Fct ".pwm" setzt PinNr & DutyCycle 0-1023 
    delay(DUTYCYCLE_LOOP_TIME);                          // kurz warten, damit man was sieht 
  }  // for
  delay(REPEAT_TIME);                                    // Warten, dann beginnt Programm von vorne
}  // loop 
