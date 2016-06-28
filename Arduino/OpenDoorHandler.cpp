#include "OpenDoorHandler.h"

OpenDoorHandler::OpenDoorHandler(Porta *porta) {
    this->porta = porta;
}

OpenDoorHandler::~OpenDoorHandler() {

}

void OpenDoorHandler::handle(EthernetClient client, RequestParser& requestParser) {
    porta->destrancar();
    porta->abrir();

    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& OpenDoorHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["aberta"] = porta->estaAberta();
    json["trancada"] = porta->estaTrancada();
    return json;
}
