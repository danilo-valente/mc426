#ifndef GAS_H
#define GAS_H

#include <Arduino.h>

#include "Device.h"
#include "Audio.h"
#include "Lampada.h"

class Gas : public Device {
private:
    uint8_t pinGas;
    uint32_t minValue;
    Audio *audio;
    Lampada *light;
public:
    Gas(uint8_t pinGas, uint32_t minValue, Audio *audio, Lampada *light);
    virtual ~Gas();
    
    void setup();
    void loop();
};

#endif /* GAS_H */
