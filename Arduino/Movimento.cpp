/*
 * Movimento.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "Movimento.h"

Movimento::Movimento(uint8_t pinPir, uint16_t minValue, Audio *audio, Lampada *light) : pinPir(pinPir), minValue(minValue), audio(audio), light(light) {
}

Movimento::~Movimento() {
}

void Movimento::setup() {
    state = false;
    value = 0;
    pinMode(pinPir, INPUT);
    digitalWrite(pinPir, LOW);
}

void Movimento::loop() {
    if (digitalRead(pinPir) == HIGH) {
        if (value == 0) {
            Serial.println("Motion started!");
        }
        if (!state && value >= minValue) {
            audio->ativar();
            light->acender();
            Serial.println("Motion detected!");
            state = true;
        }
        if (value < minValue) {
            value++;
        }
    } else {
        if (state) {
            audio->desativar();
            light->apagar();
            Serial.println("Motion ended!");
            state = false;
        }
        value = 0;
    }
    audio->loop();
}

uint8_t Movimento::pin() {
    return pinPir;
}

uint8_t Movimento::type() {
    return Device::MOVEMENT;
}

