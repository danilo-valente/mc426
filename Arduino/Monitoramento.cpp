/*
 * Monitoramento.cpp
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#include "Monitoramento.h"

Monitoramento::Monitoramento() {
    status = false;
    count = 0;
}

Monitoramento::~Monitoramento() {
}

void Monitoramento::setup() {
    int i;
    for (i = 0; i < count; i++) {
        devices[i]->setup();
    }
}

void Monitoramento::loop() {
    int i;
    if (status) {
        for (i = 0; i < count; i++) {
            devices[i]->loop();
        }
    }
}

void Monitoramento::addDevice(Device *device) {
    devices[count] = device;
    count++;
}

/*
 * Retorna o status atual
 */
bool Monitoramento::getStatus() {
    return status;
}

/*
 * Tenta ativar o monitoramento
 * Se ja estiver ativado, retorna false
 * Se estiver desativado, ativa e retorna true
 */
bool Monitoramento::ativar() {
    if (status) {
        return false;
    }

    status = true;
    return true;
}

/*
 * Tentar desativar o monitoramento
 * Se ja estiver desativado, retorna false
 * Se estiver ativado, desativa e retorna true
 */
bool Monitoramento::desativar() {
    if (!status) {
        return false;
    }

    status = false;
    return true;
}

String Monitoramento::toString() {
    return status ? "Monitoramento ativado." : "Monitoramento desativado.";
}
