/*

  faderIndividual
  Created by: Jonathan Bumstead
  Copyright: One Bit Kit 2018

  Upload this program onto the Bucky Glow to make individual pentagons on
  dodecahedron fade in and out with one color.

  All code is protected by Creative Commons copyright license: Attribution-NonCommercial-ShareAlike 2.5 Generic (CC BY-NC-SA 2.5)

*/


#include <Adafruit_WS2801.h>
#define numLeds 11
#define numLedOn 3//

Adafruit_WS2801 strip = Adafruit_WS2801(11, A0, A1);
int ledInd[numLedOn];
byte LEDind[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

int numScales = 58;
double scaleA[] = {0,0.034483,0.068966,0.10345,0.13793,0.17241,0.2069,0.24138,0.27586,0.31034,0.34483,0.37931,0.41379,0.44828,0.48276,0.51724,0.55172,0.58621,0.62069,0.65517,0.68966,0.72414,0.75862,0.7931,0.82759,0.86207,0.89655,0.93103,0.96552,1,0.96552,0.93103,0.89655,0.86207,0.82759,0.7931,0.75862,0.72414,0.68966,0.65517,0.62069,0.58621,0.55172,0.51724,0.48276,0.44828,0.41379,0.37931,0.34483,0.31034,0.27586,0.24138,0.2069,0.17241,0.13793,0.10345,0.068966,0.034483};

byte red = 250; // red value ranging from 0 to 255
byte green = 100; // green value ranging from 0 to 255
byte blue = 20; // blue value ranging from 0 to 255

void setup() {

  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
  colorAll(Color(0, 0, 0));
  
}

void loop() {

 for (int i = 0; i < numLedOn; i++)
  {
    int r1 = random(numLeds);
    ledInd[i] = r1;
  }

  for (int p = 0; p < 21; p++)
  {
    double scale = scaleA[p];

    for (int i = 0; i < numLedOn; i++)
    {
      int a = ledInd[i];
      strip.setPixelColor(a, Color(red * scale, green * scale, blue * scale));

    }

    
    strip.show();
    delay(50);
  } 
  
  colorAll(Color(0, 0, 0));

}


void colorAll(uint32_t c) {

  int i;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(LEDind[i], c);
  }

  strip.show();
}


// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;

  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(LEDind[i], c);
    strip.show();
    delay(wait);
  }
}

/* Helper functions */
// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}
