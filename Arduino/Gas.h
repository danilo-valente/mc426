/*
 * Gas.h
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#ifndef GAS_H
#define GAS_H

#include <Arduino.h>

#include "Device.h"

class Gas : Device {
private:
    uint8_t pinGas;
public:
    Gas(uint8_t pinGas);
    virtual ~Gas();
    
    void setup();
    void loop();
    int readGas();
};

#endif /* GAS_H */
