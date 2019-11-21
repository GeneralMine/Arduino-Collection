#include <Adafruit_NeoPixel.h>

#define PIN 6
#define PixelAnz 90

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PixelAnz, PIN, NEO_GRB + NEO_KHZ800);

typedef enum {
        AliceBlue=0xF0F8FF,
        Amethyst=0x9966CC,
        AntiqueWhite=0xFAEBD7,
        Aqua=0x00FFFF,
        Aquamarine=0x7FFFD4,
        Azure=0xF0FFFF,
        Beige=0xF5F5DC,
        Bisque=0xFFE4C4,
        Black=0x000000,
        BlanchedAlmond=0xFFEBCD,
        Blue=0x0000FF,
        BlueViolet=0x8A2BE2,
        Brown=0xA52A2A,
        BurlyWood=0xDEB887,
        CadetBlue=0x5F9EA0,
        Chartreuse=0x7FFF00,
        Chocolate=0xD2691E,
        Coral=0xFF7F50,
        CornflowerBlue=0x6495ED,
        Cornsilk=0xFFF8DC,
        Crimson=0xDC143C,
        Cyan=0x00FFFF,
        DarkBlue=0x00008B,
        DarkCyan=0x008B8B,
        DarkGoldenrod=0xB8860B,
        DarkGray=0xA9A9A9,
        DarkGreen=0x006400,
        DarkKhaki=0xBDB76B,
        DarkMagenta=0x8B008B,
        DarkOliveGreen=0x556B2F,
        DarkOrange=0xFF8C00,
        DarkOrchid=0x9932CC,
        DarkRed=0x8B0000,
        DarkSalmon=0xE9967A,
        DarkSeaGreen=0x8FBC8F,
        DarkSlateBlue=0x483D8B,
        DarkSlateGray=0x2F4F4F,
        DarkTurquoise=0x00CED1,
        DarkViolet=0x9400D3,
        DeepPink=0xFF1493,
        DeepSkyBlue=0x00BFFF,
        DimGray=0x696969,
        DodgerBlue=0x1E90FF,
        FireBrick=0xB22222,
        FloralWhite=0xFFFAF0,
        ForestGreen=0x228B22,
        Fuchsia=0xFF00FF,
        Gainsboro=0xDCDCDC,
        GhostWhite=0xF8F8FF,
        Gold=0xFFD700,
        Goldenrod=0xDAA520,
        Gray=0x808080,
        Green=0x008000,
        GreenYellow=0xADFF2F,
        Honeydew=0xF0FFF0,
        HotPink=0xFF69B4,
        IndianRed=0xCD5C5C,
        Indigo=0x4B0082,
        Ivory=0xFFFFF0,
        Khaki=0xF0E68C,
        Lavender=0xE6E6FA,
        LavenderBlush=0xFFF0F5,
        LawnGreen=0x7CFC00,
        LemonChiffon=0xFFFACD,
        LightBlue=0xADD8E6,
        LightCoral=0xF08080,
        LightCyan=0xE0FFFF,
        LightGoldenrodYellow=0xFAFAD2,
        LightGreen=0x90EE90,
        LightGrey=0xD3D3D3,
        LightPink=0xFFB6C1,
        LightSalmon=0xFFA07A,
        LightSeaGreen=0x20B2AA,
        LightSkyBlue=0x87CEFA,
        LightSlateGray=0x778899,
        LightSteelBlue=0xB0C4DE,
        LightYellow=0xFFFFE0,
        Lime=0x00FF00,
        LimeGreen=0x32CD32,
        Linen=0xFAF0E6,
        Magenta=0xFF00FF,
        Maroon=0x800000,
        MediumAquamarine=0x66CDAA,
        MediumBlue=0x0000CD,
        MediumOrchid=0xBA55D3,
        MediumPurple=0x9370DB,
        MediumSeaGreen=0x3CB371,
        MediumSlateBlue=0x7B68EE,
        MediumSpringGreen=0x00FA9A,
        MediumTurquoise=0x48D1CC,
        MediumVioletRed=0xC71585,
        MidnightBlue=0x191970,
        MintCream=0xF5FFFA,
        MistyRose=0xFFE4E1,
        Moccasin=0xFFE4B5,
        NavajoWhite=0xFFDEAD,
        Navy=0x000080,
        OldLace=0xFDF5E6,
        Olive=0x808000,
        OliveDrab=0x6B8E23,
        Orange=0xFFA500,
        OrangeRed=0xFF4500,
        Orchid=0xDA70D6,
        PaleGoldenrod=0xEEE8AA,
        PaleGreen=0x98FB98,
        PaleTurquoise=0xAFEEEE,
        PaleVioletRed=0xDB7093,
        PapayaWhip=0xFFEFD5,
        PeachPuff=0xFFDAB9,
        Peru=0xCD853F,
        Pink=0xFFC0CB,
        Plaid=0xCC5533,
        Plum=0xDDA0DD,
        PowderBlue=0xB0E0E6,
        Purple=0x800080,
        Red=0xFF0000,
        RosyBrown=0xBC8F8F,
        RoyalBlue=0x4169E1,
        SaddleBrown=0x8B4513,
        Salmon=0xFA8072,
        SandyBrown=0xF4A460,
        SeaGreen=0x2E8B57,
        Seashell=0xFFF5EE,
        Sienna=0xA0522D,
        Silver=0xC0C0C0,
        SkyBlue=0x87CEEB,
        SlateBlue=0x6A5ACD,
        SlateGray=0x708090,
        Snow=0xFFFAFA,
        SpringGreen=0x00FF7F,
        SteelBlue=0x4682B4,
        Tan=0xD2B48C,
        Teal=0x008080,
        Thistle=0xD8BFD8,
        Tomato=0xFF6347,
        Turquoise=0x40E0D0,
        Violet=0xEE82EE,
        Wheat=0xF5DEB3,
        White=0xFFFFFF,
        WhiteSmoke=0xF5F5F5,
        Yellow=0xFFFF00,
        YellowGreen=0x9ACD32
    } HTMLColorCode;

//   setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);   (Pixelnummer und jede Farbe extra (RGB))
//   setPixelColor(uint16_t n, uint32_t c);                        (Pixelnummer und 32 bit Farbe)

int waitKurz = 900;
int waitExtraKurz = 600;
int onTime = 1000;
int offTime = 400;
uint8_t wipeSp = 30;
int lowLimit = -100;
int highLimit = 355;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop()
{
//  strip.setPixelColor(0, Yellow);               //         (Pixelnummer und 32 bit Farbe)
//  strip.show();                                 //          Anzeige (Refresh) 
//  delay(waitKurz);
  // Some example procedures showing how to display to the pixels:
  // Alle nacheinander einschalten
  colorWipe(strip.Color(255, 0, 0), wipeSp); // Red
  delay(waitKurz);
  colorWipe(strip.Color(0, 255, 0), wipeSp); // Green
  delay(waitKurz);
  colorWipe(OrangeRed, wipeSp);               // Orange
  delay(waitKurz);
  colorWipe(strip.Color(0, 0, 255), wipeSp); // Blue
  delay(waitKurz);
  colorWipe(Yellow, wipeSp);                  // Yellow
  delay(waitKurz);
  colorWipe(White, wipeSp);                   // White
  delay(waitKurz);
  colorWipe(strip.Color(0, 0, 0), wipeSp);    // AUS
  delay(waitKurz);

  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50, 20); // White
  clearPixels();
  delay(waitKurz);
  theaterChase(strip.Color(127, 0, 0), 50, 30); // Red
  clearPixels();
  delay(waitKurz);
  theaterChase(strip.Color(0, 0, 127), 50, 40); // Blue
  clearPixels();
  delay(waitKurz);
  theaterChase(strip.Color(0, 127, 0), 50, 50); // Green
  clearPixels();
  delay(waitKurz);

  for(int i=0; i< 5; i++) {
    rainbow(10);
    clearPixels();
    delay(waitExtraKurz);
  }
  rainbow(100);
  clearPixels();
  delay(waitKurz);

  rainbowCycle(20);
  clearPixels();
  delay(waitExtraKurz);

  colorBlink(Red, onTime, offTime);
  colorBlink(Green, onTime, offTime);
  colorBlink(OrangeRed, onTime, offTime);
  colorBlink(Blue, onTime, offTime);
  colorBlink(Yellow, onTime, offTime);
  colorBlink(White, onTime, offTime);
  
  theaterChaseRainbow(50);
  clearPixels();
  delay(waitKurz);

  for(int i=0; i< 5; i++) {
    colorWipeRandom(50);
    clearPixels();
    delay(waitKurz);
  }

}  // loop
// ***************************** loop ***********************************

// Fill all the dots at the same time in a given color
void colorAllOn(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }    
  strip.show();
}

void colorBlink(uint32_t c, int onTime, int offTime) {
  colorAllOn(c);
  delay(onTime);
  clearPixels();
  delay(offTime);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

// Fill the dots one after the other with a color
void colorWipeRandom(uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {

      int tst1 = random(lowLimit, highLimit);
      int tst2 = random(lowLimit, highLimit);
      int tst3 = random(lowLimit, highLimit);
      tst1 = constrain(tst1, 0, 255);
      tst2 = constrain(tst2, 0, 255);
      tst3 = constrain(tst3, 0, 255);
//      Serial.print(tst1);
//      Serial.print(",  ");
//      Serial.print(tst2);
//      Serial.print(",  ");
//      Serial.println(tst3);
//      Serial.println((byte)tst);
      strip.setPixelColor(i, tst1, tst2, tst3);
      strip.show();
      delay(wait);
  }  // for
}

// All Pixels OFF
void clearPixels() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 0);
  }
  strip.show();
}


void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) {         // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait, uint8_t cycles) {
  for (int j=0; j<cycles; j++) {             //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

