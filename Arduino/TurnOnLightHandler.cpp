#ifndef TURN_OFF_LIGHT_HANDLER_C
#define TURN_OFF_LIGHT_HANDLER_C

#include "TurnOnLightHandler.h"

TurnOnLightHandler::TurnOnLightHandler(Lampada *lampada) {
    this->lampada = lampada;
}

TurnOnLightHandler::~TurnOnLightHandler() {
}

void TurnOnLightHandler::handle(EthernetClient client) {
    lampada->acender();

    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& TurnOnLightHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["acesa"] = lampada->estaAcesa();
    return json;
}

#endif /* TURN_OFF_LIGHT_HANDLER_C */
