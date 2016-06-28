#ifndef DEVICE_H
#define DEVICE_H

class Device {
public:
    virtual void setup() = 0;
    virtual void loop() = 0;
    virtual uint8_t pin();
    virtual uint8_t type();

    static const uint8_t DEVICE_MANAGER = 0;
    static const uint8_t WEB_SERVER = 1;
    static const uint8_t MONITORING = 2;
    static const uint8_t AUDIO = 3;
    static const uint8_t GAS = 4;
    static const uint8_t LIGHT = 5;
    static const uint8_t MOVEMENT = 6;
    static const uint8_t TANK = 7;
    static const uint8_t FLAME = 8;
};

#endif /* DEVICE_H */
