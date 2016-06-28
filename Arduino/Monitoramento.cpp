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
    for (uint8_t i = 0; i < count; i++) {
        devices[i]->setup();
    }
}

void Monitoramento::loop() {
    if (status) {
        for (uint8_t i = 0; i < count; i++) {
            devices[i]->loop();
        }
    }
}

uint8_t Monitoramento::pin() {
    return (uint8_t) -1;
}

uint8_t Monitoramento::type() {
    return Device::MONITORING;
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

    Serial.println("Monitoring enabled");
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

    Serial.println("Monitoring disabled");
    status = false;
    return true;
}

String Monitoramento::toString() {
    return status ? "Monitoramento ativado." : "Monitoramento desativado.";
}
