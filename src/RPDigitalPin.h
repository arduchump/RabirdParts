#ifndef __INCLUDED_AF8C9CAC1C2A11E7AA6EA088B4D1658C
#define __INCLUDED_AF8C9CAC1C2A11E7AA6EA088B4D1658C

#include "RPConfig.h"

class RPDigitalPin
{
public:
  RPDigitalPin();
  ~RPDigitalPin();

  void
  begin(uint8_t pin, uint8_t mode);

  void
  end();

  uint8_t
  pin();
  uint8_t
  mode();

  uint8_t
  read();

  void
  write(uint8_t value);

private:
  uint8_t mPin; ///< Pin number of this part
  uint8_t mMode : 2;
};

#define RP_DIGITAL_PIN_MODE(pin) pin##Mode

#endif // __INCLUDED_AF8C9CAC1C2A11E7AA6EA088B4D1658C
