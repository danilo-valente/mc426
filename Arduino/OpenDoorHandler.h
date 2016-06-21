#ifndef OPEN_DOOR_HANDLER_H
#define OPEN_DOOR_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "Porta.h"

class OpenDoorHandler : public EndpointHandler {
private:
    Porta *porta;
public:
    OpenDoorHandler(Porta *porta);
    virtual ~OpenDoorHandler();
    virtual void handle(EthernetClient client);
    virtual JsonObject& toJson();
};

#endif /* OPEN_DOOR_HANDLER_H */
