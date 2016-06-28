/*
 * Movimento.h
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <Arduino.h>

#include "Device.h"
#include "Audio.h"
#include "Lampada.h"

class Movimento : public Device {
private:
  	uint8_t pinPir;
    uint16_t minValue;
    Audio *audio;
    Lampada *light;
    bool state;
    uint16_t value;

public:
    Movimento(uint8_t pinPir, uint16_t minValue, Audio *audio, Lampada *light);
    virtual ~Movimento();
    
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
};

#endif /* MOVIMENTO_H */
