#include "RPBasicPin.h"

RPBasicPin::RPBasicPin() : mPin(0), mMode(INPUT)
{
}

RPBasicPin::~RPBasicPin()
{
}

uint8_t
RPBasicPin::pin()
{
  return mPin;
}

uint8_t
RPBasicPin::mode()
{
  return mMode;
}

void
RPBasicPin::begin(uint8_t pin, uint8_t mode)
{
  mPin  = pin;
  mMode = mode;

  pinMode(mPin, mMode);
}

void
RPBasicPin::end()
{
  mPin  = 0;
  mMode = INPUT;
}
