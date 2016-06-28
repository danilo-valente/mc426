#ifndef ENABLE_MONITORING_HANDLER_H
#define ENABLE_MONITORING_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "Monitoramento.h"

class EnableMonitoringHandler : public EndpointHandler {
private:
    Monitoramento *monitoring;
public:
    EnableMonitoringHandler(Monitoramento *monitoring);
    virtual ~EnableMonitoringHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson();
};

#endif /* ENABLE_MONITORING_HANDLER_H */
