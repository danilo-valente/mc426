#include "CloseDoorHandler.h"

CloseDoorHandler::CloseDoorHandler(Porta *porta) {
    this->porta = porta;
}

CloseDoorHandler::~CloseDoorHandler() {
}

void CloseDoorHandler::handle(EthernetClient client) {
    porta->fechar();
    porta->trancar();

    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& CloseDoorHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["aberta"] = porta->estaAberta();
    json["trancada"] = porta->estaTrancada();
    return json;
//    StaticJsonBuffer<200> *jsonBuffer = new StaticJsonBuffer<200>();
//    JsonObject *json = new JsonObject(new StaticJsonBuffer<200>());
//    (*json)["aberta"] = porta->aberta;
//    (*json)["trancada"] = porta->trancada;
//    return json;
}
