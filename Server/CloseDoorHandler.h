using namespace std;

#include <map>
#include <string>
#include <Ethernet.h>
#include <json/json.h>
#include "EndpointHandler.h"
#include "Porta.h"

#ifndef CLOSE_DOOR_HANDLER_H
#define CLOSE_DOOR_HANDLER_H

class CloseDoorHandler : public EndpointHandler {
public:
    CloseDoorHandler(Porta p);
    virtual ~OpenDoorHandler();
    virtual string handle();
    virtual string toJson();
    Porta porta;
};

#endif /* CLOSE_DOOR_HANDLER_H */
