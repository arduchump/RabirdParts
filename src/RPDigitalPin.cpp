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
  if(OUTPUT == (mode() & RP_PIN_IO_MASK))
  {
    return mWroteValue;
  }

  return static_cast<uint8_t>(digitalRead(pin()));
}

void
RPDigitalPin::write(uint8_t value)
{
  if(INPUT == (mode() & RP_PIN_IO_MASK))
  {
    return;
  }

  digitalWrite(pin(), value);
  mWroteValue = value;
}
