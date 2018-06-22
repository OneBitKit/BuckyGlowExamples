/*

  LEDonly
  Created by: Jonathan Bumstead
  Copyright: One Bit Kit 2018

  Upload this program onto the Bucky Glow to produce illumination patterns. Saved patterns from the Bucky Glow app 
  are copied into this program in the section title "INSERT PATTERN from BUCKY app here:" An example pattern is 
  included in the code.

  All code is protected by Creative Commons copyright license: Attribution-NonCommercial-ShareAlike 2.5 Generic (CC BY-NC-SA 2.5)

*/

#include <Adafruit_WS2801.h>
#define numLEDS 11

Adafruit_WS2801 strip = Adafruit_WS2801(numLEDS, A0, A1);
int ledActual[numLEDS]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

// INSERT PATTERN from BUCKY app here:

#define numberOfPatterns 15
byte r[numLEDS * numberOfPatterns] = {128, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 128, 128, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 128, 128, 128, 128, 128, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
byte g[numLEDS * numberOfPatterns] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 127, 127, 127, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 127, 127, 127, 127};
byte b[numLEDS * numberOfPatterns] ={0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0};

// END PATTERN INSERT

int delayTime =370;

void setup() {
  
  strip.begin(); // begin LED strip

  // Update LED contents, to start they are all 'off'
  strip.show();
  colorAll(Color(0, 0, 0));

}

void loop() {

  colorDodec(r,g,b,ledActual); // function for playing pattern on Bucky Glow
  
}

void colorDodec(byte r[], byte g[], byte b[], int ledActual[]) {

  int count = 0;

  for (int j = 0; j < numberOfPatterns; j++) {

    for (int i = 0; i < numLEDS; i++) {
      
      uint32_t c=Color(r[count],g[count],b[count]); // convert RGB to color
      strip.setPixelColor(ledActual[i], c); // send color to LED strip
      count++;
    }
    
    strip.show(); // display pattern
    delay(delayTime); // delay time between patterns in sequence

  }

}

void colorAll(uint32_t c) {

  int i;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }

  strip.show();
}



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
