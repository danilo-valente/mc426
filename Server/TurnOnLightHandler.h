using namespace std;

#include <map>
#include <string>
#include <Ethernet.h>
#include <json/json.h>
#include "EndpointHandler.h"
#include "Lampada.h"

#ifndef TURN_ON_LIGHT_HANDLER_H
#define TURN_ON_LIGHT_HANDLER_H

class TurnOnLightHandler : public EndpointHandler {
public:
    TurnOnLightHandler(Lampada l);
    virtual ~TurnOnLightHandler();
    virtual string handle();
    virtual string toJson();
    Lampada lampada;
};

#endif /* TURN_ON_LIGHT_HANDLER_H */
