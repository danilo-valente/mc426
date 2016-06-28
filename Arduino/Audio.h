#ifndef AUDIO_H
#define AUDIO_H

#include <Arduino.h>

#include "Device.h"

class Audio : public Device {
private:
    uint8_t pwmPin;
    uint16_t freq;
    uint16_t maxVal;
    uint16_t val2; // variable to store the read value
    bool ativado;
    bool flag;

public:
    Audio(uint8_t pwmPin, uint16_t freq, uint16_t maxVal);
    virtual ~Audio();
    
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
    
    void desativar();
    void ativar();
};

#endif /* AUDIO_H */
