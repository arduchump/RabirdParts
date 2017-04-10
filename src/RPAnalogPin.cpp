#include "RPAnalogPin.h"

RPAnalogPin::RPAnalogPin() : mWroteValue(0)
{
}

int
RPAnalogPin::read()
{
  if(OUTPUT == (mode() & RP_PIN_IO_MASK))
  {
    return mWroteValue;
  }

  return analogRead(pin());
}

void
RPAnalogPin::write(int value)
{
  if(INPUT == (mode() & RP_PIN_IO_MASK))
  {
    return;
  }

  analogWrite(pin(), value);
  mWroteValue = value;
}
