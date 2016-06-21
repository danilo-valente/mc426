/*
 * Lampada.cpp
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#include "Lampada.h"

Lampada::Lampada(uint8_t pinRele): pinRele(pinRele) {
    acesa = false;

    pinMode(pinRele, OUTPUT);
    digitalWrite(pinRele, HIGH);
}

Lampada::~Lampada() {
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
    digitalWrite(pinRele, LOW);

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
    digitalWrite(pinRele, HIGH);

    if (acesa) {
        acesa = false;
        return true;
    }

    return false;
}

String Lampada::toString() {
    return acesa ? "Lampada esta ligada." : "Lampada esta desligada";
}
