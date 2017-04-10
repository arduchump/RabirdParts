/*
 * RPSwitcher.h
 *
 * @date 2017-04-08
 * @author Hong-She Liang <starofrainnight@gmail.com>
 */

#ifndef __INCLUDED_D625BC021C1D11E7AA6EA088B4D1658C
#define __INCLUDED_D625BC021C1D11E7AA6EA088B4D1658C

#include <RRawPointer.h>

class RPDigitalPin;

/**
 * @brief The RPSwitcher class
 *
 * A switcher is a part that only have two status, one for ON, another for OFF.
 *
 * The switcher could be set as input or output mode. When switcher at input
 * mode, that means we controlling something just like LED, otherwise the
 * switcher indicating something just like button when at output mode.
 */
class RPSwitcher
{
public:
  enum Status
  {
    Off,
    On,
  };

public:
  RPSwitcher();
  ~RPSwitcher();

  void
  begin(RPDigitalPin *pin, uint8_t onLevel=HIGH);
  void
  begin(uint8_t pin, uint8_t mode, uint8_t onLevel=HIGH);

  void
  end();

  uint8_t
  onLevel();

  /// Simple method to switch switcher to On status
  void
  on();

  /// Simple method to switch switcher to Off status
  void
  off();

  void
  setStatus(Status status);
  Status
  status();

  RRawPointer<RPDigitalPin>
  pin();

private:
  RRawPointer<RPDigitalPin> mPin;
  uint8_t mOnLevel      : 1;
  Status  mStatus       : 1;
  bool    mIsPinManaged : 1;
};

#define RP_SWITCHER_PIN_ON_LEVEL(pinName) pin##OnLevel
#define RP_SWITCHER_BEGIN_ARGS(pinName) \
  RP_PIN_BEGIN_ARGS(pinName), (RP_SWITCHER_PIN_ON_LEVEL(pinName))

#endif /* __INCLUDED_D625BC021C1D11E7AA6EA088B4D1658C */
