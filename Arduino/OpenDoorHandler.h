#ifndef OPEN_DOOR_HANDLER_H
#define OPEN_DOOR_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "DeviceManager.h"
#include "Porta.h"

class OpenDoorHandler : public EndpointHandler {
private:
    DeviceManager *devices;
public:
    OpenDoorHandler(DeviceManager *devices);
    virtual ~OpenDoorHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson(Porta *porta);
};

#endif /* OPEN_DOOR_HANDLER_H */
