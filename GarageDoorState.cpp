#include "GarageDoorState.h"

GarageDoorState::GarageDoorState() {
  relay = new Relay(D6, RELAY_MOMENTARY_MODE);
}

int GarageDoorState::getState() {
  if (distance <= DOOR_OPEN_DISTANCE) {
    return STATE_OPEN;
  } else if (distance >= DOOR_CLOSED_DISTANCE) {
    return STATE_CLOSED;
  }
  return STATE_TRANSITION;
}

int GarageDoorState::setDistance(int distance) {
  this->distance = distance;
}

void GarageDoorState::callback(int payload) {
  if (payload == SWITCH_OPEN_DOOR_PAYLOAD) {
    relay->trigger();
  } else {
    relay->trigger();
  }
}

