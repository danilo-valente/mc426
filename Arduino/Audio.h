#ifndef AUDIO_H
#define AUDIO_H

#include <Arduino.h>

#include "Device.h"

class Audio : public Device {
private:
    uint8_t pwmPin;
    uint32_t freq;
    uint32_t maxVal;
    uint32_t val2; // variable to store the read value
    bool ativado;
    bool flag;

public:
    Audio(uint8_t pwmPin, uint32_t freq, uint32_t maxVal);
    virtual ~Audio();
    
    void setup();
    void loop();
    void desativar();
    void ativar();
};

#endif /* AUDIO_H */
