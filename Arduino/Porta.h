#ifndef PORTA_H_
#define PORTA_H_

#include <Arduino.h>

class Porta {
private:
	uint8_t pinMotor;
	uint8_t pinTranca;
	bool aberta;
	bool trancada;
public:
	Porta(uint8_t pinMotor, uint8_t pinTranca);
	virtual ~Porta();

	bool estaAberta();
	bool estaTrancada();
	int trancar();
	int destrancar();
	int abrir();
	int fechar();
	String toString();
};

#endif /* PORTA_H_ */
