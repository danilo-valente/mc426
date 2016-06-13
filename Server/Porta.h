/*
 * Porta.h


 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */
using namespace std;
#include <iostream>

#ifndef PORTA_H_
#define PORTA_H_

class Porta {
public:
	Porta(int pinMotor, int pinTranca);
	virtual ~Porta();
	bool aberta;
	bool trancada;
	int pinMotor;
	int pinTranca;

	int trancar();
	int destrancar();
	int abrir();
	int fechar();
	string toString();
};

#endif /* PORTA_H_ */
