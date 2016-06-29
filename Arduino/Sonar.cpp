#include "Sonar.h"

Sonar::Sonar(uint8_t pinSonarWrite, uint8_t pinSonarRead, uint16_t maxDistance, uint8_t pinLed) : pinSonarWrite(pinSonarWrite),
                                                                                                  pinSonarRead(pinSonarRead),
                                                                                                  maxDistance(maxDistance),
                                                                                                  pinLed(pinLed) {
}

Sonar::~Sonar() {
}

void Sonar::setup() {
    if (ultrasonic) {
        delete ultrasonic;
    }

    pinMode(pinSonarWrite, OUTPUT);
    pinMode(pinSonarRead, INPUT);
    pinMode(pinLed, OUTPUT);
    ultrasonic = new Ultrasonic(pinSonarRead, pinSonarWrite);
}

void Sonar::loop() {
    // Variaveis para guardar os valores em 
    // cm (cmSec) e polegadas (inMsec)
    float cmMsec, inMsec;
    
    // Le os valores do sensor ultrasonico
    uint64_t microsec = ultrasonic->timing();
    // Atribui os valores em cm ou polegadas as variaveis
    cmMsec = ultrasonic->convert(microsec, Ultrasonic::CM);
    inMsec = ultrasonic->convert(microsec, Ultrasonic::IN);
    if (cmMsec < maxDistance) {
        digitalWrite(pinLed, HIGH);
    } else {
        digitalWrite(pinLed, LOW);
    }
    
    // Mostra os valores na serial
    Serial.print("Centimetros: ");
    Serial.println(cmMsec);
    Serial.print("Polegadas: ");
    Serial.println(inMsec);
}

uint8_t Sonar::pin() {
    return pinSonarRead;
}

uint8_t Sonar::type() {
    return Device::SONAR;
}

