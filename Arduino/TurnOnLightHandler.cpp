#ifndef TURN_OFF_LIGHT_HANDLER_C
#define TURN_OFF_LIGHT_HANDLER_C

#include "TurnOnLightHandler.h"

TurnOnLightHandler::TurnOnLightHandler(DeviceManager *devices): devices(devices) {
}

TurnOnLightHandler::~TurnOnLightHandler() {
}

void TurnOnLightHandler::handle(EthernetClient client, RequestParser& requestParser) {
    uint8_t pin = (uint8_t) requestParser.get("i").toInt();
    Lampada *lampada = (Lampada *) this->devices->find(pin, Device::LIGHT);

    if (lampada != NULL) {
        lampada->acender();
    }

    JsonObject& json = toJson(lampada);
    json.printTo(client);
}

JsonObject& TurnOnLightHandler::toJson(Lampada *lampada) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    if (lampada != NULL) {
        json["acesa"] = lampada->estaAcesa();
    } else {
        json["error"] = 400;
    }
    return json;
}

#endif /* TURN_OFF_LIGHT_HANDLER_C */
