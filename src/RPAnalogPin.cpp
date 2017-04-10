#include "RPAnalogPin.h"

RPAnalogPin::RPAnalogPin() : mWroteValue(0)
{
}

int
RPAnalogPin::read()
{
  if(OUTPUT == mode())
  {
    return mWroteValue;
  }

  return analogRead(pin());
}

void
RPAnalogPin::write(int value)
{
  if(OUTPUT != mode())
  {
    return;
  }

  analogWrite(pin(), value);
  mWroteValue = value;
}
