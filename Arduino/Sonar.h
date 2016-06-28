/*
 * Sonar.h
 *
 *  Created on: 17 de jun de 2016
 *      Author: Menf
 */

#ifndef SONAR_H
#define SONAR_H

#include <Arduino.h>
#include <Ultrasonic.h>

class Sonar {
private:
    uint8_t pinSonarRead;
    uint8_t pinSonarWrite;
  	uint16_t maxDistance;
  	Ultrasonic *ultrasonic;
public:
  	Sonar(uint8_t pinSonarRead, uint8_t pinSonarWrite, uint16_t maxDistance);
  	virtual ~Sonar();
  
  	uint16_t readDistance();
};

#endif /* SONAR_H */
