#include <HSBColor.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define PixelAnz 240

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PixelAnz, PIN, NEO_GRB + NEO_KHZ800);

int pixels[3][PixelAnz];
int rgb [3];
int hue;

void setup()
{
  strip.begin();
}


void loop()
{
  for(int j=0;j<PixelAnz;j++)
  {
    for(int i=0;i<PixelAnz;i++)
    {
      hue=(i+j)*6;
      if(hue>=360)
      {
      hue=hue-360;
      }
      H2R_HSBtoRGB(hue,100,10,rgb);
      strip.setPixelColor(i,rgb[0],rgb[1],rgb[2]);
    }
    strip.show();
    delay(5);
  }

}




