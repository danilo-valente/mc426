/*
 * Sonar.cpp
 *
 *  Created on: 17 de jun de 2016
 *      Author: Menf
 */

#include "Sonar.h"

Sonar::Sonar(uint8_t pinSonarRead, uint8_t pinSonarWrite, uint16_t maxDistance) : pinSonarRead(pinSonarRead), pinSonarWrite(pinSonarWrite), maxDistance(maxDistance) {
//    pinMode(pinSonar, INPUT);
//    ultrasonic(pinSonar, 11, maxDistance);
    ultrasonic = new Ultrasonic(pinSonarRead, pinSonarWrite);
}

Sonar::~Sonar() {
}

uint16_t Sonar::readDistance(){
    return ultrasonic->convert(ultrasonic->timing(), Ultrasonic::CM);
}
