#include "Power.h"

Power::Power(uint8_t emonPin, uint8_t powerPin, uint8_t calibration, uint16_t samples, uint32_t scale, uint8_t precision): emonPin(emonPin),
                                                                                                                           powerPin(powerPin),
                                                                                                                           calibration(calibration),
                                                                                                                           samples(samples),
                                                                                                                           scale(scale),
                                                                                                                           precision(precision) {
}

Power::~Power() {
}

void Power::setup() {
    pinMode(emonPin, INPUT);
    pinMode(powerPin, INPUT);
    power = 0;
    total = 0;
    totalKWh = 0;
    emon.current(emonPin, calibration);
}

void Power::loop() {
    double volt = analogRead(powerPin);
    double irms = volt > 0 ? emon.calcIrms(samples) : 0;
    
    irms /= precision; // fio passa 5 vezes no sensor, aumenta a precisão! (quanto mais vezes, melhor)
    
    Serial.print(irms);// Apparent power
    Serial.print("\t"); 
  
    if (volt > 90){
        volt -= 90; // pela montagem ta pegando duas fases, entao aqui desconto uma fase
    }
    
    Serial.print(volt); // Voltagem
    Serial.print("\t");
  
    power = irms * volt;
    total += power; // calculo da curva de energia de consumo em Joules/segundo ou Watts
    totalKWh = total / scale; // transforma em kWh
    
    Serial.print(power);// É o consumo em tempo real
    Serial.print("\t");
    Serial.print(totalKWh);// em kWh
    Serial.print("\n");
}

uint8_t Power::pin() {
    return powerPin;
}

uint8_t Power::type() {
    return Device::POWER;
}

double Power::getPower() {
    return power;
}

double Power::getTotal() {
    return total;
}

double Power::getTotalKWh() {
    return totalKWh;
}
