#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
// #define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
       FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
//  	  FastLED.addLeds<NEOPIXEL, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() { 
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
//  leds[1] = CRGB(255,0,0);
  leds[1] = CRGB::Green;
//  leds[2] = CRGB(0,255,0);
  leds[2] = CRGB::Blue;
 
//  leds[0].r = 0;     // set red for LED 10 (Color = Red + Green + Blue)
//  leds[0].g = 0;       // set green for LED 10
//  leds[0].b = 255;       // set blue for LED 10

  FastLED.show();       // Show changes
  delay(1000);
  
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  FastLED.show();
  delay(500);
  
  for (int i = 0; i < NUM_LEDS; i++)
  {  // Set the i'th led to red 
    leds[i] = CRGB::Red;
    FastLED.show();           // Show the leds
    leds[i] = CRGB::Black;    // now that we've shown the leds, reset the i'th led to black
    delay(100);               // Wait a little bit before we loop around and do it again
  }
  // Now go in the other direction.  
  for(int i = NUM_LEDS-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CRGB::Red;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
    delay(100);
  }

  for(int x = 0; x < 256; x++) { 
  // The showColor method sets all the leds in the strip to the same color
    LEDS.showColor(CRGB(x, 0, 0));
    delay(10);
  }

  for(int x = 0; x < 256; x++) { 
  // The showColor method sets all the leds in the strip to the same color
    LEDS.showColor(CRGB(0, x, 0));
    delay(10);
  }

  for(int x = 0; x < 256; x++) { 
  // The showColor method sets all the leds in the strip to the same color
    LEDS.showColor(CRGB(0, 0, x));
    delay(10);
  }

  for(int x = 0; x < 256; x++) { 
  // The showColor method sets all the leds in the strip to the same color
    LEDS.showColor(CRGB(x, x, x));
    delay(10);
  }

  delay(500);
}
