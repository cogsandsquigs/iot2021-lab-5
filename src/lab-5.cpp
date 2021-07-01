/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/ianp/Documents/iot2021/labs/lab-5/src/lab-5.ino"
void setup();
void loop();
#line 1 "/home/ianp/Documents/iot2021/labs/lab-5/src/lab-5.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

const uint16_t in = A5;  // input pin
const uint16_t out = D6; // output pin
int minValue = 4096;     // minimum value recorded
int maxValue = 0;        // maximum value recorded

void setup()
{
  pinMode(in, INPUT);
  pinMode(out, OUTPUT);
  Serial.begin(9600); // begins serial output for debugging + being cool :)
}

void loop()
{
  int value = analogRead(in);
  Serial.println(value);

  if (value > maxValue)      // this whole bit right here
  {                          // keeps track of the
    maxValue = value;        // minimum and maximum values
  }                          // recorded, and adjusts the map accordingly
  else if (value < minValue) // so that I can be lazy
  {                          // and dont have to record
    minValue = value;        // the min and max values myself.
  }                          // :p

  uint32_t returnValue = map(value, minValue, maxValue, 255, 0); // maps min and max values to 255, 0; inversed b/c inverse effects
  analogWrite(out, returnValue);
}