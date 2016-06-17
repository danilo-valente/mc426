using namespace std;

#include <map>
#include <string>
#include <Ethernet.h>
#include <json/json.h>
#include "EndpointHandler.h"
#include "Lampada.h"

#ifndef TURN_OFF_LIGHT_HANDLER_H
#define TURN_OFF_LIGHT_HANDLER_H

class TurnOffLightHandler : public EndpointHandler {
public:
    TurnOnLightHandler(Lampada l);
    virtual ~TurnOnLightHandler();
    virtual string handle();
    virtual string toJson();
    Lampada lampada;
};

#endif /* TURN_OFF_LIGHT_HANDLER_H */
