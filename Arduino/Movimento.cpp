/*
 * Movimento.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "Movimento.h"

Movimento::Movimento(uint8_t pinMovOut, int setupTime) : pinMovOut(pinMovOut), setupTime(setupTime) {
    pinMode(pinMovOut, INPUT);
//    digitalWrite(pinMovOut, LOW);
}

Movimento::~Movimento() {
}

void Movimento::calibrate() {
    Serial.print("Calibrando sensor ");
    for (int i = 0; i < setupTime; i++) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println(" Done");
    Serial.println("Sensor de Movimento Calibrado");
    delay(50);
}

int Movimento::readStatus() {
    return digitalRead(pinMovOut);
}

