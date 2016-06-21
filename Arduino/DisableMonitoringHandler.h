#ifndef DISABLE_MONITORING_HANDLER_H
#define DISABLE_MONITORING_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "Monitoramento.h"

class DisableMonitoringHandler : public EndpointHandler {
private:
    Monitoramento *monitoring;
public:
    DisableMonitoringHandler(Monitoramento *monitoring);
    virtual ~DisableMonitoringHandler();
    virtual void handle(EthernetClient client);
    virtual JsonObject& toJson();
};

#endif /* DISABLE_MONITORING_HANDLER_H */
