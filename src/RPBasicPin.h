#ifndef __INCLUDED_16B953281D9011E7AA6EA088B4D1658C
#define __INCLUDED_16B953281D9011E7AA6EA088B4D1658C

#include "RPConfig.h"

class RPBasicPin
{
public:
  RPBasicPin();
  ~RPBasicPin();

  uint8_t
  pin();

  uint8_t
  mode();

  void
  begin(uint8_t pin, uint8_t mode);

  void
  end();

private:
  uint8_t mPin; ///< Pin number of this part
  uint8_t mMode : 2;
};

#define RP_PIN_MODE(pin) pin##Mode

#endif // __INCLUDED_16B953281D9011E7AA6EA088B4D1658C
