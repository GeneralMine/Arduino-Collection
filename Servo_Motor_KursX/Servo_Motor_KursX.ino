/*
Steuert einen SERVO Motor an. Dazu wird das Servo Objekt verwendet
Die Position des Servo wird mit einem Poti eingestellt und der Wert seriell
angezeigt   */

#include <Servo.h>                      // Einbinden der SERVO Bibliothek 
 
Servo meinServo;                        // erzeugt ein Servo object  "meinServo" um den SERVO-Motor zu steuern 
 
// int potiPin = 0;                        // analoger Pin für das Potentiometer
int potiPin = A5;                        // analoger Pin für das Potentiometer
int wert;                               // variable um den Poti Wert vom Analog Pin zu lesen & speichern 
int oldWert = 0;                        // variable um den Poti Wert vom Analog Pin zu lesen & speichern 
 
void setup() 
{ 
//  meinServo.attach(9);                  // an PWM Pin 9 wird der Servo angeschlossen 
  meinServo.attach(3);                  // an PWM Pin 9 wird der Servo angeschlossen 
  Serial.begin(9600);                   // Serielle Schnittstelle mit 9600 baud initialisieren 
} 
 
 void loop() 
{ 
  wert = analogRead(potiPin);          // liest den Poti Wert (Wert zwischen 0 und 1023) 
  wert = map(wert, 0, 1023, 0, 179);   // scaliert den Wert auf einen Servo tauglichen Wert zwischen 0 und 180) 
  if (wert != oldWert)
  {
    Serial.println(wert);                // Servo Wert seriell anzeigen
    oldWert = wert;
  }  
  meinServo.write(wert);               // übergibt den scalierten Wert und setzt damit die SERVO Position 
  delay(20);                           // wartet eine Weile bis der SERVO eingestellt ist 
}
