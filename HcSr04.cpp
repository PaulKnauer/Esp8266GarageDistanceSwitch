#include "HcSr04.h"

HcSr04::HcSr04(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long HcSr04::getDurationInMicroseconds() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long pulse = pulseIn(echoPin, HIGH);
  if (MIN_DURATION >= pulse) {
    return MIN_DURATION;
  } else if (MAX_DURATION <= pulse) {
    return MAX_DURATION;
  }
  return pulse;
}

long HcSr04::getDistanceInCm() {
  return getDurationInMicroseconds() / 29 / 2;
}

long HcSr04::getDistanceInInches() {
  return getDurationInMicroseconds() / 74 / 2;
}

