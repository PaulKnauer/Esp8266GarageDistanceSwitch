#ifndef HcSr04_h
#define HcSr04_h

#define MIN_DURATION 116
#define MAX_DURATION 11600

#include "Arduino.h"

class HcSr04 {
  public:
    HcSr04(int trigPin, int echoPin);
    long getDurationInMicroseconds();
    long getDistanceInCm();
    long getDistanceInInches();
  private:
    int trigPin;
    int echoPin;
};

#endif
