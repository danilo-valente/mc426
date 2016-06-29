#ifndef PORTA_H_
#define PORTA_H_

#include <Arduino.h>
#include <Servo.h> 
#include <Stepper.h>

#include "Device.h"

class Porta : public Device {
private:
	uint8_t pinMotor;
	uint8_t pinTranca;
    Servo servo;
    Servo servoLock;
	bool aberta;
	bool trancada;
public:
    Porta(uint8_t pinMotor, uint8_t pinTranca);
    virtual ~Porta();

    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();

    bool estaAberta();
    bool estaTrancada();
    int trancar();
    int destrancar();
    int abrir();
    int fechar();
    String toString();
};

#endif /* PORTA_H_ */
