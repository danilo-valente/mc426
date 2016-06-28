#ifndef POWER_H
#define POWER_H

#include <Arduino.h>
#include <EmonLib.h>

#include "Device.h"

class Power : public Device {
private:
    uint8_t emonPin;
    uint8_t powerPin;
    uint8_t calibration;
    uint16_t samples;
    uint32_t scale;
    uint8_t precision;
    EnergyMonitor emon;
    double power;
    double total;
    double totalKWh;

public:
    Power(uint8_t emonPin, uint8_t powerPin, uint8_t calibration, uint16_t samples, uint32_t scale, uint8_t precision);
    virtual ~Power();

    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();

    double getPower();
    double getTotal();
    double getTotalKWh();
};

#endif /* POWER_H */
