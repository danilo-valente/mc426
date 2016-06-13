using namespace std;

#include <map>
#include <string>
#include <Ethernet.h>
#include <json/json.h>
#include "EndpointHandler.h"
#include "Porta.h"

#ifndef OPEN_DOOR_HANDLER_H
#define OPEN_DOOR_HANDLER_H

class OpenDoorHandler : public EndpointHandler {
public:
    OpenDoorHandler(Porta p);
    virtual ~OpenDoorHandler();
    virtual string handle(EthernetClient client);
    virtual string toJson();
    Porta porta;
};

#endif /* OPEN_DOOR_HANDLER_H */
