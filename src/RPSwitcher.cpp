/*
 * RPSwitcher.cpp
 *
 * @date 2016-12-05
 * @author Hong-She Liang <starofrainnight@gmail.com>
 */

#include "RPSwitcher.h"

RPSwitcher::RPSwitcher()
  : mPin(0)
  , mMode(INPUT)
  , mOnLevel(LOW)
  , mStatus(Off)
{
}

RPSwitcher::~RPSwitcher()
{
  int a;

  a++;
}

void
RPSwitcher::begin(uint8_t pin, uint8_t mode, uint8_t onLevel)
{
  mPin     = pin;
  mMode    = mode;
  mOnLevel = onLevel;

  pinMode(mPin, mMode);
  off(); // All switcher will be default to off status
}

uint8_t
RPSwitcher::pin()
{
  return mPin;
}

uint8_t
RPSwitcher::mode()
{
  return mMode;
}

uint8_t
RPSwitcher::onLevel()
{
  return mOnLevel;
}

void
RPSwitcher::on()
{
  setStatus(On);
}

void
RPSwitcher::off()
{
  setStatus(Off);
}

RPSwitcher::Status
RPSwitcher::status()
{
  if(OUTPUT == mMode)
  {
    return mStatus;
  }
  else
  {
    return ((digitalRead(pin()) == onLevel()) ? On : Off);
  }
}

void
RPSwitcher::setStatus(RPSwitcher::Status status)
{
  if(OUTPUT == mMode)
  {
    if(On == status)
    {
      digitalWrite(mPin, onLevel());
    }
    else
    {
      digitalWrite(mPin, (onLevel() == HIGH) ? LOW : HIGH);
    }

    mStatus = status;
  }
}
