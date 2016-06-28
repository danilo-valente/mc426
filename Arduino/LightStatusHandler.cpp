#include "LightStatusHandler.h"

LightStatusHandler::LightStatusHandler(DeviceManager *devices): devices(devices) {
}

LightStatusHandler::~LightStatusHandler() {
}

void LightStatusHandler::handle(EthernetClient client, RequestParser& requestParser) {
    uint8_t pin = (uint8_t) requestParser.get("i").toInt();
    Lampada *lampada = (Lampada *) this->devices->find(pin, Device::LIGHT);

    JsonObject& json = toJson(lampada);
    json.printTo(client);
}

JsonObject& LightStatusHandler::toJson(Lampada *lampada) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    if (lampada != NULL) {
        json["acesa"] = lampada->estaAcesa();
    } else {
        json["error"] = 400;
    }
    return json;
}
