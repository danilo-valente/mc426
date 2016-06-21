/*
 * Porta.cpp
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#include "Porta.h"

Porta::Porta(uint8_t pinMotor, uint8_t pinTranca): pinMotor(pinMotor), pinTranca(pinTranca) {
    aberta = false;
    trancada = false;

    pinMode(pinMotor, OUTPUT);
    pinMode(pinTranca, OUTPUT);
}

Porta::~Porta() {
}

bool Porta::estaAberta() {
    return aberta;
}

bool Porta::estaTrancada() {
    return trancada;
}

/*
 * Tenta trancar a porta
 * Se estiver fechada e destrancada, tranca e retorna true
 * Se estiver aberta ou trancada, retorna false
 */
int Porta::trancar() {
    if (trancada || aberta) {
        return false;
    }

    // TODO: digitalWrite
    trancada = true;
    return true;
}

/*
 * Tenta destrancar a porta
 * Se estiver fechada e trancada, destranca e retorna true
 * Se estiver aberta ou destrancada, retorna false
 */
int Porta::destrancar() {
    if (!trancada || aberta) {
        return false;
    }

    // TODO: digitalWrite
    trancada = false;
    return true;
}

/*
 * Tenta abrir a porta
 * Se estiver fechada, destranca, abre e retorna true
 * Se estiver aberta, retorna false
 */
int Porta::abrir() {
    if (aberta) {
        return false;
    }

    aberta = true;
    destrancar();
    // TODO: digitalWrite
    return true;
}

/*
 * Tenta fechar a porta
 * Se ela estiver aberta, fecha, tranca e retorna true
 * Se ela estiver fechada, retorna false
 */
int Porta::fechar() {
    if (!aberta) {
        return false;
    }

    // TODO: digitalWrite
    aberta = false;
    trancar();
    return true;
}

String Porta::toString() {
    if (aberta) {
        return "Porta esta aberta.";
    }

    String aux = "Porta esta fechada e ";
    if (trancada) {
        aux += "trancada.";
    } else {
        aux += "destrancada.";
    }

    return aux;
}