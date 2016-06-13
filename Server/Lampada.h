#include <iostream>
using namespace std;
/*
 * Lampada.h
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#ifndef LAMPADA_H_
#define LAMPADA_H_

class Lampada {
public:
	Lampada(int pinL);
	virtual ~Lampada();

	bool acesa;
	int pinLampada;

	int acender();
	int apagar();
	string toString();
};

#endif /* LAMPADA_H_ */
