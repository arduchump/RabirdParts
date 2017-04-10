#ifndef __INCLUDED_16B953281D9011E7AA6EA088B4D1658C
#define __INCLUDED_16B953281D9011E7AA6EA088B4D1658C

#include "RPConfig.h"

#define RP_PIN_INVALID 255

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

  bool
  isValid();

private:
  uint8_t mPin; ///< Pin number of this part
  uint8_t mMode : 2;
};

#define RP_PIN_MODE(pinName)       pin##Mode
#define RP_PIN_BEGIN_ARGS(pinName) (pinName), RP_PIN_MODE(pinName)

#endif // __INCLUDED_16B953281D9011E7AA6EA088B4D1658C
