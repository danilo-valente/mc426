#ifndef TANK_H
#define TANK_H

#include <Arduino.h>

#include "Device.h"
#include "Audio.h"

class Tank : public Device {
private:
    uint8_t tankPin;
    Audio *audio;
    bool state;

public:
    Tank(uint8_t tankPin, Audio *audio);
    virtual ~Tank();
    
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
};

#endif /* TANK_H */
