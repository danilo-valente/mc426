/*
 * Gas.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "Gas.h"

Gas::Gas(uint8_t pinGas, uint16_t minValue, Audio *audio, Lampada *light) : pinGas(pinGas), minValue(minValue), audio(audio), light(light) {
}

Gas::~Gas() {
}

void Gas::setup() {
    state = false;
    pinMode(pinGas, INPUT);
}

void Gas::loop() {
    uint16_t value = analogRead(pinGas);
    if (value > minValue) {
        if (!state) {
            Serial.println("Smoke detected");
            state = true;
            audio->ativar();
            light->acender();
        }
    } else {
        if (state) {
            Serial.println("Smoke dissipated");
            state = false;
            audio->desativar();
            light->apagar();
        }
    }
    audio->loop();
}

uint8_t Gas::pin() {
    return pinGas;
}

uint8_t Gas::type() {
    return Device::GAS;
}

