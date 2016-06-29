#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "Device.h"

#define DM_MAX_DEVICES 20

class DeviceManager : public Device {
private:
    Device *devices[DM_MAX_DEVICES];
    uint8_t count;
public:
    DeviceManager();
    virtual ~DeviceManager();
    
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
    
    void add(Device *device);
    Device *find(uint8_t pin);
    Device *find(uint8_t pin, uint8_t type);
};

#endif /* DEVICE_MANAGER_H */
