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
#include "Lampada.h"

class Movimento : public Device {
private:
  	uint8_t pinPir;
    uint32_t state;
    Lampada *light;

public:
    Movimento(uint8_t pinPir, Lampada *light);
    virtual ~Movimento();
    
    void setup();
    void loop();
};

#endif /* MOVIMENTO_H */
