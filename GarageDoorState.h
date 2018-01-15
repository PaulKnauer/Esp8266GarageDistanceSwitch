#ifndef GarageDoorState_h
#define GarageDoorState_h

#include "UserConfig.h"
#include "EventCallback.h"
#include "Relay.h"

class GarageDoorState : public EventCallback {
  public:
    GarageDoorState();
    int getState();
    int setDistance(int distance);
    void callback(int payload);
  private:
    int distance;
    Relay *relay;
};

#endif
