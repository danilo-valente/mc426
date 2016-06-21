#ifndef TURN_ON_LIGHT_HANDLER_H
#define TURN_ON_LIGHT_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "Lampada.h"

class TurnOnLightHandler : public EndpointHandler {
private:
    Lampada *lampada;
public:
    TurnOnLightHandler(Lampada *lampada);
    virtual ~TurnOnLightHandler();
    virtual void handle(EthernetClient client);
    virtual JsonObject& toJson();
};

#endif /* TURN_ON_LIGHT_HANDLER_H */
