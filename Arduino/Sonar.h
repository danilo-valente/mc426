#ifndef SONAR_H
#define SONAR_H

#include <Arduino.h>
#include <Ultrasonic.h>

#include "Device.h"

class Sonar : public Device {
private:
    uint8_t pinSonarWrite;
    uint8_t pinSonarRead;
  	uint16_t maxDistance;
    uint8_t pinLed;
  	Ultrasonic *ultrasonic;
public:
    Sonar(uint8_t pinSonarWrite, uint8_t pinSonarRead, uint16_t maxDistance, uint8_t pinLed);
    virtual ~Sonar();

    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
};

#endif /* SONAR_H */
