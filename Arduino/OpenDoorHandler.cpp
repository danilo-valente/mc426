#include "OpenDoorHandler.h"

OpenDoorHandler::OpenDoorHandler(DeviceManager *devices): devices(devices) {
}

OpenDoorHandler::~OpenDoorHandler() {
}

void OpenDoorHandler::handle(EthernetClient client, RequestParser& requestParser) {
    uint8_t pin = (uint8_t) requestParser.get("i").toInt();
    Porta *porta = (Porta *) this->devices->find(pin, Device::DOOR);

    if (porta != NULL) {
        porta->abrir();
    }

    JsonObject& json = toJson(porta);
    json.printTo(client);
}

JsonObject& OpenDoorHandler::toJson(Porta *porta) {
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
