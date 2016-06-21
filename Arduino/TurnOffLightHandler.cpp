#include "TurnOffLightHandler.h"

TurnOffLightHandler::TurnOffLightHandler(Lampada *lampada) {
    this->lampada = lampada;
}

TurnOffLightHandler::~TurnOffLightHandler() {

}

void TurnOffLightHandler::handle(EthernetClient client) {
    lampada->apagar();

    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& TurnOffLightHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["acesa"] = lampada->estaAcesa();
    return json;
}
