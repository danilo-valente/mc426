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
  	int maxDistance;
  	Ultrasonic *ultrasonic;
public:
  	Sonar(uint8_t pinSonarRead, uint8_t pinSonarWrite, int maxDistance);
  	virtual ~Sonar();
  
  	int readDistance();
};

#endif /* SONAR_H */
