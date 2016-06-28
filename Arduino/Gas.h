#ifndef GAS_H
#define GAS_H

#include <Arduino.h>

#include "Device.h"
#include "Audio.h"
#include "Lampada.h"

class Gas : public Device {
private:
    uint8_t pinGas;
    uint16_t minValue;
    Audio *audio;
    Lampada *light;
    bool state;
public:
    Gas(uint8_t pinGas, uint16_t minValue, Audio *audio, Lampada *light);
    virtual ~Gas();
    
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
};

#endif /* GAS_H */
