#ifndef CLOSE_DOOR_HANDLER_H
#define CLOSE_DOOR_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "DeviceManager.h"
#include "Porta.h"

class CloseDoorHandler : public EndpointHandler {
private:
    DeviceManager *devices;
public:
    CloseDoorHandler(DeviceManager *devices);
    virtual ~CloseDoorHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson(Porta *porta);
};

#endif /* CLOSE_DOOR_HANDLER_H */
