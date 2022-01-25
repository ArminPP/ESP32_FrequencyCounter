

#include <Arduino.h>
#include "FreqCountESP.h"

uint8_t inputPin = 32;
uint16_t timerMs = 1000;

void setup()
{
  Serial.begin(115200);                  // Serial Console Arduino 115200 Bps
  Serial.println(" FreqCounterESP lib"); // Console print
  FreqCountESP.begin(inputPin, timerMs);
}

void loop()
{
  static unsigned long o = 0;

  if (FreqCountESP.available())
  {
    unsigned long t = millis();
    uint32_t frequency = FreqCountESP.read();
    Serial.printf("Time %lu ms  -  Frequency %i Hz\n", t-o, frequency);
    o = t;
  }
}
