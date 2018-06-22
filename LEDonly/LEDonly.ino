/*

  LEDonly
  Created by: Jonathan Bumstead
  Copyright: One Bit Kit 2018

  Upload this program onto the Arduino to produce illumination patterns. 

  The BuckyGlow App can be downloaded on our GitHub: https://github.com/OneBitKit

  All code is protected by Creative Commons copyright license: Attribution-NonCommercial-ShareAlike 2.5 Generic (CC BY-NC-SA 2.5)
*/

#include <Adafruit_WS2801.h>
#define numLEDS 11

Adafruit_WS2801 strip = Adafruit_WS2801(numLEDS, A0, A1);
int ledActual[numLEDS]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

// INSERT PATTERN from BUCKY app here:
#define numberOfPatterns 15A
byte r[numLEDS * numberOfPatterns] = {128, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 128, 128, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 128, 128, 128, 128, 128, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
byte g[numLEDS * numberOfPatterns] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 127, 127, 127, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 127, 127, 127, 127};
byte b[numLEDS * numberOfPatterns] ={0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0};
// END PATTERN INSERT

int delayTime =370;

void setup() {
  // put your setup code here, to run once:
  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
  colorAll(Color(0, 0, 0));

}

void loop() {
  // put your main code here, to run repeatedly:
  colorDodec(r,g,b,ledActual);
}

void colorDodec(byte r[], byte g[], byte b[], int ledActual[]) {

  int count = 0;

  for (int j = 0; j < numberOfPatterns; j++) {

    for (int i = 0; i < numLEDS; i++) {
      
      uint32_t c=Color(r[count],g[count],b[count]);
      strip.setPixelColor(ledActual[i], c);
      count++;
    }
    
    strip.show();
    delay(delayTime);

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
