#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

#include "UserConfig.h"

class Relay {
  public:
    Relay(int triggerPin, int mode);
    void trigger();
  private:
    int triggerPin;
    int mode;
    boolean state;
};

#endif
