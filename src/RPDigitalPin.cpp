#include "RPDigitalPin.h"

RPDigitalPin::RPDigitalPin() : mWroteValue(LOW)
{
}

RPDigitalPin::~RPDigitalPin()
{
}

uint8_t
RPDigitalPin::read()
{
  if(OUTPUT == mode())
  {
    return mWroteValue;
  }

  return static_cast<uint8_t>(digitalRead(pin()));
}

void
RPDigitalPin::write(uint8_t value)
{
  if(OUTPUT != mode())
  {
    return;
  }

  digitalWrite(pin(), value);
  mWroteValue = value;
}
