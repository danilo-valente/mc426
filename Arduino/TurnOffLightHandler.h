#ifndef TURN_OFF_LIGHT_HANDLER_H
#define TURN_OFF_LIGHT_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "DeviceManager.h"
#include "Lampada.h"

class TurnOffLightHandler : public EndpointHandler {
private:
    DeviceManager *devices;
public:
    TurnOffLightHandler(DeviceManager *devices);
    virtual ~TurnOffLightHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson(Lampada *lampada);
};

#endif /* TURN_OFF_LIGHT_HANDLER_H */
