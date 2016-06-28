#include "MonitoringStatusHandler.h"

MonitoringStatusHandler::MonitoringStatusHandler(Monitoramento *monitoring) : monitoring(monitoring) {
}

MonitoringStatusHandler::~MonitoringStatusHandler() {
}

void MonitoringStatusHandler::handle(EthernetClient client, RequestParser& requestParser) {
    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& MonitoringStatusHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["status"] = monitoring->getStatus();
    return json;
}
