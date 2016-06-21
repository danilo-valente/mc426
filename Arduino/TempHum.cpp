/*
 * TempHum.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "TempHum.h"

TempHum::TempHum(uint8_t pinHum, int typeHum) : pinHum(pinHum), typeHum(typeHum) {
    pinMode(pinHum, INPUT);
    dht = new DHT(pinHum, typeHum);
    dht->begin();
}

TempHum::~TempHum() {
}

float TempHum::readHumidity() {
    return dht->readHumidity();
}

float TempHum::readTemperature() {
    return dht->readTemperature();
}