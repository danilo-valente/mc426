#include "DoorStatusHandler.h"

DoorStatusHandler::DoorStatusHandler(DeviceManager *devices): devices(devices) {
}

DoorStatusHandler::~DoorStatusHandler() {
}

void DoorStatusHandler::handle(EthernetClient client, RequestParser& requestParser) {
    uint8_t pin = (uint8_t) requestParser.get("i").toInt();
    Porta *porta = (Porta *) this->devices->find(pin, Device::DOOR);

    JsonObject& json = toJson(porta);
    json.printTo(client);
}

JsonObject& DoorStatusHandler::toJson(Porta *porta) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    if (porta != NULL) {
        json["aberta"] = porta->estaAberta();
        json["trancada"] = porta->estaTrancada();
    } else {
        json["error"] = 400;
    }
    return json;
}
