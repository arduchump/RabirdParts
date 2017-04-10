#ifndef __INCLUDED_4A2E56F41D8B11E7AA6EA088B4D1658C
#define __INCLUDED_4A2E56F41D8B11E7AA6EA088B4D1658C

#include "RPBasicPin.h"

/**
 * @brief The RPAnalogPin class
 *
 *
 *
 * @ref https://www.arduino.cc/en/Tutorial/AnalogInputPins
 */
class RPAnalogPin : public RPBasicPin
{
public:
  RPAnalogPin();

  int
  read();

  void
  write(int value);

private:
  int mWroteValue;
};

#endif // __INCLUDED_4A2E56F41D8B11E7AA6EA088B4D1658C
