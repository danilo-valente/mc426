/*
 * TempHum.cpp
 *
 *  Created on: 16 de jun de 2016
 *      Author: Menf
 */

#include "TempHum.h"

TempHum::TempHum(uint8_t pinDHT, uint8_t typeDHT, uint8_t pinHeater, uint8_t pinFan, float minTFan, float maxTHeater) : pinDHT(pinDHT),
                                                                                                                        typeDHT(typeDHT),
                                                                                                                        pinHeater(pinHeater),
                                                                                                                        pinFan(pinFan),
                                                                                                                        maxTHeater(maxTHeater),
                                                                                                                        minTFan(minTFan) {
}

TempHum::~TempHum() {
}

void TempHum::setup() {
    if (dht) {
        delete dht;
    }

    temperature = 0;
    humidity = 0;
    
    pinMode(pinDHT, INPUT);
    pinMode(pinHeater, OUTPUT);
    pinMode(pinFan, OUTPUT);
    digitalWrite(pinHeater, HIGH);
    digitalWrite(pinFan, HIGH);
    dht = new DHT(pinDHT, typeDHT);
    dht->begin();
}

void TempHum::loop() {
    temperature = dht->readTemperature();

    if (isnan(temperature))  {
        Serial.println("Failed to read from DHT");
    } else {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" ºC");
        
        digitalWrite(pinHeater, temperature <= maxTHeater ? LOW : HIGH);
        digitalWrite(pinFan, temperature >= minTFan ? LOW : HIGH);
    }
    
    humidity = dht->readHumidity();
    if (isnan(humidity))  {
        Serial.println("Failed to read from DHT");
    } else {
        Serial.print("Humidity: ");
        Serial.println(humidity);
    }
}

uint8_t TempHum::pin() {
    return pinDHT;
}

uint8_t TempHum::type() {
    return Device::TEMP_HUM;
}

float TempHum::getTemperature() {
    return temperature;
}

float TempHum::getHumidity() {
    return humidity;
}

