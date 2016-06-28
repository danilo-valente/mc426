/*
 * Monitoramento.h
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#ifndef MONITORAMENTO_H
#define MONITORAMENTO_H

#include <Arduino.h>

#include "Device.h"

#define MONITORING_MAX_DEVICES 10

class Monitoramento : public Device {
private:
  	bool status;
    Device *devices[MONITORING_MAX_DEVICES];
    uint8_t count;

public:
  	Monitoramento();
  	virtual ~Monitoramento();
  
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
    
    void addDevice(Device *device);
  	bool ativar();
  	bool desativar();
  	bool getStatus();
  	String toString();
};

#endif /* MONITORAMENTO_H */
