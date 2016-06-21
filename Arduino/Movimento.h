/*
 * Movimento.h
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <Arduino.h>

class Movimento {
private:
	uint8_t pinMovOut;
	int setupTime;

public:
	Movimento(uint8_t pinMovOut, int setupTime);
	virtual ~Movimento();

	int readStatus();
	void calibrate();

};

#endif /* MOVIMENTO_H */
