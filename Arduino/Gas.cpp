/*
 * Gas.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "Gas.h"

Gas::Gas(uint8_t pinGas) : pinGas(pinGas) {
}

Gas::~Gas() {
}

void Gas::setup() {
  pinMode(pinGas, INPUT);
}

void Gas::loop() {
  // TODO
}

int Gas::readGas(){
	return analogRead(pinGas);
}
