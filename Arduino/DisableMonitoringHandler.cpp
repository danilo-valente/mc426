#include "DisableMonitoringHandler.h"

DisableMonitoringHandler::DisableMonitoringHandler(Monitoramento *monitoring) : monitoring(monitoring) {
}

DisableMonitoringHandler::~DisableMonitoringHandler() {
}

void DisableMonitoringHandler::handle(EthernetClient client) {
    monitoring->desativar();

    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& DisableMonitoringHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["status"] = monitoring->getStatus();
    return json;
}
