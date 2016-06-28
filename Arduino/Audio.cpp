#include "Audio.h"

Audio::Audio(uint8_t pwmPin, uint16_t freq, uint16_t maxVal) : pwmPin(pwmPin), freq(freq), maxVal(maxVal) {
    val2 = 0;
    ativado = false;
    flag = false;
}

Audio::~Audio() {
}

void Audio::setup() {
    pinMode(pwmPin, OUTPUT); // sets the pin as output
//    TCCR3B = (TCCR3B & 0b11111000) | freq;
}

void Audio::loop() {
    if (ativado) {
        analogWrite(pwmPin, val2);
        
        if (val2 == maxVal) {
            flag = false;
        } else if (val2 == 0) {
            flag = true;
        }
    
        if (flag) {
            val2++;
        } else {
            val2--;
        }
    
        delay(7);
    } else {
        digitalWrite(pwmPin, LOW);
    }
}

uint8_t Audio::pin() {
    return pwmPin;
}

uint8_t Audio::type() {
    return Device::AUDIO;
}

void Audio::desativar() {
    Serial.println("Alarm disabled");
    ativado = false;
}

void Audio::ativar() {
    Serial.println("Alarm enabled");
    ativado = true;
}

