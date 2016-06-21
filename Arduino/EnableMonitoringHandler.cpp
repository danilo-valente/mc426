#include "EnableMonitoringHandler.h"

EnableMonitoringHandler::EnableMonitoringHandler(Monitoramento *monitoring) : monitoring(monitoring) {
}

EnableMonitoringHandler::~EnableMonitoringHandler() {
}

void EnableMonitoringHandler::handle(EthernetClient client) {
    monitoring->ativar();

    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& EnableMonitoringHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["status"] = monitoring->getStatus();
    return json;
}
