#ifndef CLOSE_DOOR_HANDLER_H
#define CLOSE_DOOR_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "Porta.h"

class CloseDoorHandler : public EndpointHandler {
private:
    Porta *porta;
public:
    CloseDoorHandler(Porta *p);
    virtual ~CloseDoorHandler();
    virtual void handle(EthernetClient client);
    virtual JsonObject& toJson();
};

#endif /* CLOSE_DOOR_HANDLER_H */
