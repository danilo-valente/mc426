/*
 * Movimento.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "Movimento.h"

Movimento::Movimento(uint8_t pinPir, Lampada *light) : pinPir(pinPir), light(light) {
    state = LOW;
}

Movimento::~Movimento() {
}

void Movimento::setup() {
    Serial.println("Movimento::setup");
    pinMode(pinPir, INPUT);
    digitalWrite(pinPir, LOW);
}

void Movimento::loop() {
    Serial.println("Movimento::loop");
    if (digitalRead(pinPir) == HIGH) {
        if (state == LOW) {
            light->acender();
            Serial.println("Motion detected!");
            state = HIGH;
        }
    } else {
        if (state == HIGH) {
            light->apagar();
            Serial.println("Motion ended!");
            state = LOW;
        }
    }
}
