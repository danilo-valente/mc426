/*
 * TempHum.h
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#ifndef TEMPHUM_H
#define TEMPHUM_H

#include <Arduino.h>
#include <DHT.h>

#include "Device.h"

class TempHum : public Device {
private:
  	uint8_t pinDHT;
  	uint8_t typeDHT;
    uint8_t pinHeater;
    uint8_t pinFan;
    float maxTHeater;
    float minTFan;
  	DHT *dht;
    float temperature;
    float humidity;
public:
  	TempHum(uint8_t pinDHT, uint8_t typeDHT, uint8_t pinHeater, uint8_t pinFan, float maxTHeater, float minTFan);
  	virtual ~TempHum();

    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
    
  	float getTemperature();
  	float getHumidity();
};

#endif /* TEMPHUM_H */
