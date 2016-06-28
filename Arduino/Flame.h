#ifndef FLAME_H
#define FLAME_H

#include <Arduino.h>

#include "Device.h"
#include "Audio.h"

class Flame : public Device {
private:
    uint8_t flamePin;
    Audio *audio;
    bool state;

public:
    Flame(uint8_t flamePin, Audio *audio);
    virtual ~Flame();
    
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
};

#endif /* FLAME_H */
