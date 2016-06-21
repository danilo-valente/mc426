#ifndef LAMPADA_H_
#define LAMPADA_H_

#include <Arduino.h>

class Lampada {
private:
	bool acesa;
	uint8_t pinRele;
public:
	Lampada(uint8_t pinRele);
	virtual ~Lampada();

	bool estaAcesa();
	bool acender();
	bool apagar();
	String toString();
};

#endif /* LAMPADA_H_ */
