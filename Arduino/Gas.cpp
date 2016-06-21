/*
 * Gas.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "Gas.h"

Gas::Gas(uint8_t pinGas, uint32_t minValue, Audio *audio, Lampada *light) : pinGas(pinGas), minValue(minValue), audio(audio), light(light) {
}

Gas::~Gas() {
}

void Gas::setup() {
    pinMode(pinGas, INPUT);
}

void Gas::loop() {
    uint32_t value = analogRead(pinGas);
    if (value > minValue) {
        audio->ativar();
        light->acender();
    } else {
        audio->desativar();
        light->apagar();
    }
    audio->loop();
}
