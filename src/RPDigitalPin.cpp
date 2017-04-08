#include "RPDigitalPin.h"

RPDigitalPin::RPDigitalPin() : mPin(0), mMode(INPUT)
{
}

RPDigitalPin::~RPDigitalPin()
{
}

void
RPDigitalPin::begin(uint8_t pin, uint8_t mode)
{
  mPin  = pin;
  mMode = mode;

  pinMode(mPin, mMode);
}

void
RPDigitalPin::end()
{
}

uint8_t
RPDigitalPin::pin()
{
  return mPin;
}

uint8_t
RPDigitalPin::mode()
{
  return mMode;
}

uint8_t
RPDigitalPin::read()
{
  if(OUTPUT == mMode)
  {
    return LOW;
  }

  return static_cast<uint8_t>(digitalRead(mPin));
}

void
RPDigitalPin::write(uint8_t value)
{
  if(OUTPUT == mMode)
  {
    digitalWrite(mPin, value);
  }
}
