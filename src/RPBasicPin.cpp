#include "RPBasicPin.h"

RPBasicPin::RPBasicPin() : mPin(RP_PIN_INVALID), mMode(INPUT)
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

  /**
   * We don't have real output pull-up mode, but we emulated one :
   *
   * First we set pin mode to INPUT_PULLUP, so the internal pull-up resistor will
   * take effect, and then set pin mode to OUTPUT, this behavior won't change
   * pull-up resistor status, so it will keep at pull-up status with OUTPUT mode.
   */
  if(OUTPUT_PULLUP == mode)
  {
    pinMode(mPin, INPUT_PULLUP);
  }

  pinMode(mPin, OUTPUT);
}

void
RPBasicPin::end()
{
  mPin  = RP_PIN_INVALID;
  mMode = INPUT;
}

bool
RPBasicPin::isValid()
{
  return mPin != RP_PIN_INVALID;
}
