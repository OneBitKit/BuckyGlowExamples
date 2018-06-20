#include <CapacitiveSensor.h>
#include <Adafruit_WS2801.h>
#define numLedsReal 11

/*

  buckyApp
  Created by: Jonathan Bumstead
  Copyright: One Bit Kit 2018

  Upload this program onto the BuckyGlow to control LEDs with capacitive touch sensors.
  10 capacitive touch sensors can be connected to pins 2-12 as specified below. 

  The BuckyGlow App can be downloaded on our GitHub: https://github.com/OneBitKit

*/

CapacitiveSensor   cs_0 = CapacitiveSensor(2, 3);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 3 and copper (RECIEVE) 
CapacitiveSensor   cs_1 = CapacitiveSensor(2, 4);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 4 and copper (RECIEVE) 
CapacitiveSensor   cs_2 = CapacitiveSensor(2, 5);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 5 and copper (RECIEVE) 
CapacitiveSensor   cs_3 = CapacitiveSensor(2, 6);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 6 and copper (RECIEVE) 
CapacitiveSensor   cs_4 = CapacitiveSensor(2, 7);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 7 and copper (RECIEVE) 
CapacitiveSensor   cs_5 = CapacitiveSensor(2, 8);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 8 and copper (RECIEVE) 
CapacitiveSensor   cs_6 = CapacitiveSensor(2, 9);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 9 and copper (RECIEVE) 
CapacitiveSensor   cs_7 = CapacitiveSensor(2, 10);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 10 and copper (RECIEVE) 
CapacitiveSensor   cs_8 = CapacitiveSensor(2, 11);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 11 and copper (RECIEVE) 
CapacitiveSensor   cs_9 = CapacitiveSensor(2, 12);       // 10 megohm resistor between pin 2 and copper (SEND), 1kohm resitor peter pin 12 and copper (RECIEVE) 

long cap0; // sensor 0 measurement
long cap1; // sensor 1 measurement
long cap2; // sensor 2 measurement
long cap3; // sensor 3 measurement
long cap4; // sensor 4 measurement 
long cap5; // sensor 5 measurement
long cap6; // sensor 6 measurement
long cap7; // sensor 7 measurement
long cap8; // sensor 8 measurement
long cap9; // sensor 9 measurement
long cap10; // sensor 10 measurement
long capCut = 220; // measurment cutoff

bool hitValue[numLedsReal] =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Was cap sensor hit?
bool prevValue[numLedsReal] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Was cap sensor previously hit?

byte LEDind[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // LEDs are reversed on Bucky ball

Adafruit_WS2801 strip = Adafruit_WS2801(11, A0, A1); // create strip object

byte colRed [2] = {250,0}; // OFF ON
byte colGreen [2] = {250,0}; // OFF ON
byte colBlue [2] = {250,20}; // OFF ON

byte red[numLedsReal];    // Initialize array with vallues for LED strip
byte green[numLedsReal];    // Initialize array with vallues for LED strip
byte blue[numLedsReal];    // Initialize array with vallues for LED strip

void setup() {
  // put your setup code here, to run once:

  strip.begin(); // Start strip

  // Update LED contents, to start they are all 'off'
  colorAll(Color(colRed[1],colGreen[1],colBlue[1]));
  strip.show();
 
}

void loop() {
  // put your main code here, to run repeatedly:
  cap0 =  cs_0.capacitiveSensor(30);
  cap1 =  cs_1.capacitiveSensor(30);
  cap2 =  cs_2.capacitiveSensor(30);
  cap3 =  cs_3.capacitiveSensor(30);
  cap4 =  cs_4.capacitiveSensor(30);
  cap5 =  cs_5.capacitiveSensor(30);
  cap6 =  cs_6.capacitiveSensor(30);
  cap7 =  cs_7.capacitiveSensor(30);
  cap8 =  cs_8.capacitiveSensor(30);
  cap9 =  cs_9.capacitiveSensor(30);
  cap10 =  0;//cs_10.capacitiveSensor(30);

   // Sensor 0
  if (cap0 > capCut) {
    hitValue[0] = 0;
  }
  else if (cap0 <= capCut) {
    hitValue[0] = 1;
  }

  // Sensor 1 was hit
  if (cap1 > capCut) {
    hitValue[1] = 0;
  }
  else if (cap1 <= capCut) {
    hitValue[1] = 1;
  }

  // Sensor 2 was hit
  if (cap2 > capCut) {
    hitValue[2] = 0;
  }
  else if (cap2 <= capCut) {
    hitValue[2] = 1;
  }

  // Sensor 3 was hit
  if (cap3 > capCut) {
    hitValue[3] = 0;
  }
  else if (cap3 <= capCut) {
    hitValue[3] = 1;
  }

  // Sensor 4
  if (cap4 > capCut) {
    hitValue[4] = 0;
  }
  else if (cap4 <= capCut) {
    hitValue[4] = 1;
  }

  // Sensor 5
  if (cap5 > capCut) {
    hitValue[5] = 0;
  }
  else if (cap5 <= capCut) {
    hitValue[5] = 1;
  }

  // Sensor 6
  if (cap6 > capCut) {
    hitValue[6] = 0;
  }
  else if (cap6 <= capCut) {
    hitValue[6] = 1;
  }

  // Sensor 7
  if (cap7 > capCut) {
    hitValue[7] = 0;
  }
  else if (cap7 <= capCut) {
    hitValue[7] = 1;
  }

  // Sensor 8
  if (cap8 > capCut) {
    hitValue[8] = 0;
  }
  else if (cap8 <= capCut) {
    hitValue[8] = 1;
  }

  // Sensor 9 was hit
  if (cap9 > capCut) {
    hitValue[9] = 0;
  }
  else if (cap9 <= capCut) {
    hitValue[9] = 1;
  }

  // Sensor 10 was hit
  if (cap10 > capCut) {
    hitValue[10] = 0;
  }
  else if (cap10 <= capCut) {
    hitValue[10] = 1;
  }

  
  for (int i = 0; i < numLedsReal; i++)
  {
    
    red[LEDind[i]] = colRed[hitValue[i]];
    green[LEDind[i]] = colGreen[hitValue[i]];
    blue[LEDind[i]] = colBlue[hitValue[i]];
    prevValue[i] = hitValue[i];
  }
 colorAllGlobal();
  delay(10);
  

}


void colorAllGlobal() {
  // function to color Bucky ball according to global variables red, green, blue
  uint32_t c;
  int i;
  for (i = 0; i < strip.numPixels(); i++) {
    c = Color(red[i], green[i], blue[i]);
    strip.setPixelColor(i, c);
  }

  strip.show();
}

void colorAll(uint32_t c) {
  // function to color all of Bucky Ball one color
  int i;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }

  strip.show();
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

