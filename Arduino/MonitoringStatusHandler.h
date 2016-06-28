#ifndef MONITORING_STATUS_HANDLER_H
#define MONITORING_STATUS_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "Monitoramento.h"

class MonitoringStatusHandler : public EndpointHandler {

private:
    Monitoramento *monitoring;
public:
    MonitoringStatusHandler(Monitoramento *monitoring);
    virtual ~MonitoringStatusHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson();
};

#endif /* MONITORING_STATUS_HANDLER_H */
