/*  Description:  Dieser Sketch lässt ein angeschlossenes Piezo-Element piepsen
              Es werden unterschiedliche Töne über ein Tone-Array abgerufen.
Referenz:     http://arduino.cc/en/Reference/Array
              http://arduino.cc/en/Reference/Tone
              http://arduino.cc/en/Reference/NoTone
              http://arduino.cc/en/Reference/Delay  */

#include "pitches.h"
#define piezoPin 13             // Piezo-Element an Pin 13
#define toneDuration 800        // Ton-Dauer
#define tonePause 1200          // Pausenlänge zwischen den Tönen
#define versuche 5              // Anzahl der Wiederholungen

// Angabe der Töne mit Namen oder direkt als Frequenz
// int tones[] = {NOTE_C2, NOTE_C3, 523, 659, 587, 698, 659, 784, 698, 880, NOTE_C4, NOTE_C5};
int tones[] = {NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,
     NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6,
     NOTE_A6, NOTE_B6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7, NOTE_C8, NOTE_D8};
int elements = sizeof(tones) / sizeof(tones[0]);

void setup()
{
  noTone(piezoPin);                             // Piezo stumm schalten
  for(int n = 0; n < versuche; n++)             // Schleife mit Array-Anzahl "elements" 
  {
    for(int i = 0; i < elements; i++)             // Schleife mit Array-Anzahl "elements" 
    {
      tone(piezoPin, tones[i], toneDuration);     // Ton spielen
      delay(tonePause);                           // Pause zwischen den Tönen
    }  // for
  } // for  
}  // setup()

void loop()
{  /* leer */
}
