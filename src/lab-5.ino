SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

const uint16_t in = A5;  // input pin
const uint16_t out = D6; // output pin
int minValue = 4096;     // maximum value recorded
int maxValue = 0;        // minimum value recorded

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
  if (value > maxValue) // this whole bit right here
  {                     // keeps track of the
    maxValue = value;   // minimum and maximum values
  }                     // recorded, and adjusts the map accordingly
  else if (value < minValue)
  {
    minValue = value;
  }
  uint32_t returnValue = map(value, minValue, maxValue, 255, 0); // maps min and max values to 255, 0; inversed b/c inverse effects
  analogWrite(out, returnValue);
}