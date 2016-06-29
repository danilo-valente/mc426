#ifndef DOOR_STATUS_HANDLER_H
#define DOOR_STATUS_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "DeviceManager.h"
#include "Porta.h"

class DoorStatusHandler : public EndpointHandler {
private:
    DeviceManager *devices;
public:
    DoorStatusHandler(DeviceManager *devices);
    virtual ~DoorStatusHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson(Porta *porta);
};

#endif /* DOOR_STATUS_HANDLER_H */
