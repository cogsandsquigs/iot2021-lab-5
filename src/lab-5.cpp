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

const uint16_t in = A5;
const uint16_t out = D6;
int minValue = 4096;
int maxValue = 0;

void setup()
{
  pinMode(in, INPUT);
  pinMode(out, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(in);
  Serial.println(value);
  if (value > maxValue)
  {
    maxValue = value;
  }
  else if (value < minValue)
  {
    minValue = value;
  }
  uint32_t returnValue = map(value, minValue, maxValue, 255, 0);
  analogWrite(out, returnValue);
}