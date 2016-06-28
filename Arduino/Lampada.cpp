/*
 * Lampada.cpp
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#include "Lampada.h"

Lampada::Lampada(uint8_t pinRelay): pinRelay(pinRelay) {
    acesa = false;
}

Lampada::~Lampada() {
}

void Lampada::setup() {
    pinMode(pinRelay, OUTPUT);
    digitalWrite(pinRelay, HIGH);
}

void Lampada::loop() {
    if (acesa) {
        digitalWrite(pinRelay, LOW);
    } else {
        digitalWrite(pinRelay, HIGH);
    }
}

uint8_t Lampada::pin() {
    return pinRelay;
}

uint8_t Lampada::type() {
    return Device::LIGHT;
}

bool Lampada::estaAcesa() {
    return acesa;
}

/*
 * Tenta acender a lampada
 * Se estiver ligada, retorna false
 * Se estiver desligada, liga e retorna true
 */
bool Lampada::acender() {
    digitalWrite(pinRelay, LOW);

    if (!acesa) {
        acesa = true;
        return true;
    }

    return false;
}

/*
 * Tentar apagar a lampada
 * Se estiver apagada, retorna false
 * Se estiver ligada, apaga e retorna true
 */
bool Lampada::apagar() {
    digitalWrite(pinRelay, HIGH);

    if (acesa) {
        acesa = false;
        return true;
    }

    return false;
}

String Lampada::toString() {
    return acesa ? "Lampada esta ligada." : "Lampada esta desligada";
}
