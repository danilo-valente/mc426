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

class TempHum {
private:
	uint8_t pinHum;
	uint8_t typeHum;
	DHT *dht;
public:
	TempHum(uint8_t pinHum, uint8_t typeHum);
	virtual ~TempHum();

	float readTemperature();
	float readHumidity();

};

#endif /* TEMPHUM_H */
