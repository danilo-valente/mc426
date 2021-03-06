#ifndef TURN_ON_LIGHT_HANDLER_H
#define TURN_ON_LIGHT_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "DeviceManager.h"
#include "Lampada.h"

class TurnOnLightHandler : public EndpointHandler {
private:
    DeviceManager *devices;
public:
    TurnOnLightHandler(DeviceManager *devices);
    virtual ~TurnOnLightHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson(Lampada *lampada);
};

#endif /* TURN_ON_LIGHT_HANDLER_H */
