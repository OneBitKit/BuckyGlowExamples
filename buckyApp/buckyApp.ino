/*

  buckyApp
  Created by: Jonathan Bumstead
  Copyright: One Bit Kit 2018

  Upload this program onto the Arduino to use the BuckyGlow App.
  This program takes serial commands from the app to light up the
  dome and store up to 40 patterns. Enables user to update BuckyGlow
  patterns in real-time by clicking on the dome presented in the App.

  The BuckyGlow App can be downloaded on our GitHub: https://github.com/OneBitKit

  All code is protected by Creative Commons copyright license: Attribution-NonCommercial-ShareAlike 2.5 Generic (CC BY-NC-SA 2.5)
*/

#include <Adafruit_WS2801.h> // LED strip library
#define numLEDS 11 
#define maxStores 40 

Adafruit_WS2801 strip = Adafruit_WS2801(numLEDS, A0, A1); // create LED strip object

int r;
int b;
int g;
int whichLedInd;
int whichLed;
int whichStore;
int delayTime;

//int ledActual[11] = {8, 2, 3, 9, 10, 7, 1, 0, 4, 5, 6};
int ledActual[11]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
byte rDisp[numLEDS][maxStores];
byte gDisp[numLEDS][maxStores];
byte bDisp[numLEDS][maxStores];
int checkRun;

int readType = 0;
bool store = 0;

bool playBack = 0;

void setup() {
  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
  colorAll(Color(0, 0, 0));

  Serial.begin(9600);    //start serial communication @9600 bps
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) { //data is available to read

    playBack = 0;

    while (!Serial.available()) {}
    readType = Serial.read();

    if (readType == 0) {

      while (!Serial.available()) {}
      store = Serial.read();

      if (store == 0) {

        while (!Serial.available()) {}
        whichLedInd = Serial.read();
        whichLed = ledActual[whichLedInd]; //ledActual[whichLedInd-1];

        while (!Serial.available()) {}
        r = Serial.read();
        while (!Serial.available()) {}
        g = Serial.read();
        while (!Serial.available()) {}
        b = Serial.read();

        colorSingle(Color(r, g, b), whichLed);
        Serial.println(r);
        Serial.println(g);
        Serial.println(b);
        delay(200);

      }

      else if (store == 1)
      {

        whichStore = readInt();

        for (int d = 0; d < numLEDS; d++) {


          while (!Serial.available()) {}
          rDisp[d][whichStore] = Serial.read();
          while (!Serial.available()) {}
          gDisp[d][whichStore] = Serial.read();
          while (!Serial.available()) {}
          bDisp[d][whichStore] = Serial.read();

        }

      }

    }

    if (readType == 1) {

      colorAll(Color(0, 0, 0));
      delay(500);
      delayTime = readInt();
      checkRun = 0;

      runSequence(rDisp, gDisp, bDisp, whichStore + 1, delayTime);

    }

  }

}

void colorSingle(uint32_t c, int whichLED) {

  strip.setPixelColor(whichLED, c);
  strip.show();

}

void colorAll(uint32_t c) {

  int i;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }

  strip.show();
}

void singleStoreDisplay(byte rDisp[numLEDS][maxStores], byte gDisp[numLEDS][maxStores], byte bDisp[numLEDS][maxStores], int whichDisplay) {
  for (int i = 0; i < numLEDS; i++) {

    strip.setPixelColor(ledActual[i], Color(rDisp[i][whichDisplay], gDisp[i][whichDisplay], bDisp[i][whichDisplay]));

  }
  strip.show();

}


void runSequence(byte rDisp[numLEDS][maxStores], byte gDisp[numLEDS][maxStores], byte bDisp[numLEDS][maxStores], int totalStores, int delayTime) {
  while (checkRun != 110) {
    
    for (int currentStore = 0; currentStore < totalStores; currentStore++) {

      for (int i = 0; i < numLEDS; i++) {
        strip.setPixelColor(ledActual[i], Color(rDisp[i][currentStore], gDisp[i][currentStore], bDisp[i][currentStore]));
      }
      strip.show();

      checkRun = Serial.read();
      
      if (checkRun == 110) {     // User clicked STOP
        singleStoreDisplay(rDisp, gDisp, bDisp, totalStores-1);
        break;  //break;
      }
      delay(delayTime);
    }
    
  }
 
}

int readInt() {
  int v = 0;
  int z = Serial.read();
  while (z != 'e') {

    // handle digits
    if ((z >= '0') && (z <= '9')) {
      v = 10 * v + z - '0';
    }

    z = Serial.read();
  }
  return v;
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
