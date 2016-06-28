#include "DeviceManager.h"

DeviceManager::DeviceManager() {
    this->count = 0;
}

DeviceManager::~DeviceManager() {
}

void DeviceManager::setup() {
    for (uint8_t i = 0; i < this->count; i++) {
        this->devices[i]->setup();
    }
}

void DeviceManager::loop() {
    for (uint8_t i = 0; i < this->count; i++) {
        this->devices[i]->loop();
    }
}

uint8_t DeviceManager::pin() {
    return (uint8_t) -1;
}

uint8_t DeviceManager::type() {
    return Device::DEVICE_MANAGER;
}

void DeviceManager::add(Device *device) {
    devices[count++] = device;
}

Device * DeviceManager::find(uint8_t pin) {
    for (uint8_t i = 0; i < this->count; i++) {
        if (devices[i]->pin() == pin) {
            return devices[i];
        }
    }

    return NULL;
}

Device * DeviceManager::find(uint8_t pin, uint8_t type) {
    Device *device = this->find(pin);
    return device != NULL && device->type() == type ? device : NULL;
}
