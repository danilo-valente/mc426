#ifndef DEVICE_H
#define DEVICE_H

class Device {
public:
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif /* DEVICE_H */