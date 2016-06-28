#include "Flame.h"

Flame::Flame(uint8_t flamePin, Audio *audio): flamePin(flamePin), audio(audio) {
}

Flame::~Flame() {
}

void Flame::setup() {
    state = false;
    pinMode(flamePin, INPUT);
}

void Flame::loop() {
    uint8_t flame = digitalRead(flamePin);
    
    if (flame == LOW) {
        if (!state) {
            Serial.println("Fire detected");
            state = true;
            audio->ativar();
        }
    } else {
        if (state) {
            Serial.println("Fire extinguished");
            state = false;
            audio->desativar();
        }
    }

    audio->loop();
}

uint8_t Flame::pin() {
    return flamePin;
}

uint8_t Flame::type() {
    return Device::FLAME;
}
