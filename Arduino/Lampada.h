#ifndef LAMPADA_H_
#define LAMPADA_H_

#include <Arduino.h>

#include "Device.h"

class Lampada : public Device {
private:
  	bool acesa;
  	uint8_t pinRelay;
public:
  	Lampada(uint8_t pinRelay);
  	virtual ~Lampada();
  
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
  
  	bool estaAcesa();
  	bool acender();
  	bool apagar();
  	String toString();
};

#endif /* LAMPADA_H_ */
