#ifndef TURN_OFF_LIGHT_HANDLER_H
#define TURN_OFF_LIGHT_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "Lampada.h"

class TurnOffLightHandler : public EndpointHandler {
private:
    Lampada *lampada;
public:
    TurnOffLightHandler(Lampada *lampada);
    virtual ~TurnOffLightHandler();
    virtual void handle(EthernetClient client);
    virtual JsonObject& toJson();
};

#endif /* TURN_OFF_LIGHT_HANDLER_H */
