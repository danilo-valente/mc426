#include "Tank.h"

Tank::Tank(uint8_t tankPin, Audio *audio): tankPin(tankPin), audio(audio) {
}

Tank::~Tank() {
}

void Tank::setup() {
    state = false;
    pinMode(tankPin, INPUT);
}

void Tank::loop() {
    uint8_t val = digitalRead(tankPin);
    if (val == HIGH) {
        if (!state) {
            Serial.println("Tank is full");
            audio->ativar();
            state = true;
        }
    } else {
        if (state){
            Serial.println("Tank is not full");
            audio->desativar();
            state = false;
        }
    }

    audio->loop();
}

uint8_t Tank::pin() {
    return this->tankPin;
}

uint8_t Tank::type() {
    return Device::TANK;
}
