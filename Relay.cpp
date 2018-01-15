#include "Relay.h"

Relay::Relay(int triggerPin, int mode) {
  pinMode(triggerPin, OUTPUT);
  this->triggerPin = triggerPin;
  this->mode = mode;
  digitalWrite(triggerPin, LOW);
  state = false;
}

void Relay::trigger() {
  if (RELAY_TOGGLE_MODE == mode) {
    state = !state;
    digitalWrite(triggerPin, state);
  } else if (RELAY_MOMENTARY_MODE == mode) {
    state = false;
    digitalWrite(triggerPin, LOW);
    digitalWrite(triggerPin, HIGH);
    delay(2000);
    digitalWrite(triggerPin, LOW);
  }
}

