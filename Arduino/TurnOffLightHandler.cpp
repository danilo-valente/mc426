#include "TurnOffLightHandler.h"

TurnOffLightHandler::TurnOffLightHandler(DeviceManager *devices): devices(devices) {
}

TurnOffLightHandler::~TurnOffLightHandler() {

}

void TurnOffLightHandler::handle(EthernetClient client, RequestParser& requestParser) {
    uint8_t pin = (uint8_t) requestParser.get("i").toInt();
    Lampada *lampada = (Lampada *) this->devices->find(pin, Device::LIGHT);

    if (lampada != NULL) {
        lampada->apagar();
    }

    JsonObject& json = toJson(lampada);
    json.printTo(client);
}

JsonObject& TurnOffLightHandler::toJson(Lampada *lampada) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    if (lampada != NULL) {
        json["acesa"] = lampada->estaAcesa();
    } else {
        json["error"] = 400;
    }
    return json;
}
