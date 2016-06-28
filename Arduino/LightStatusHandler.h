#ifndef LIGHT_STATUS_HANDLER
#define LIGHT_STATUS_HANDLER

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "DeviceManager.h"
#include "Lampada.h"

class LightStatusHandler : public EndpointHandler {
private:
    DeviceManager *devices;
public:
    LightStatusHandler(DeviceManager *devices);
    virtual ~LightStatusHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson(Lampada *lampada);
};

#endif /* LIGHT_STATUS_HANDLER */
