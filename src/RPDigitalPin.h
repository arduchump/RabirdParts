#ifndef __INCLUDED_AF8C9CAC1C2A11E7AA6EA088B4D1658C
#define __INCLUDED_AF8C9CAC1C2A11E7AA6EA088B4D1658C

#include "RPBasicPin.h"

class RPDigitalPin : public RPBasicPin
{
public:
  RPDigitalPin();
  ~RPDigitalPin();

  uint8_t
  read();

  void
  write(uint8_t value);

private:
  uint8_t mWroteValue;
};

#endif // __INCLUDED_AF8C9CAC1C2A11E7AA6EA088B4D1658C
