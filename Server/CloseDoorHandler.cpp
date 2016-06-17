#include "CloseDoorHandler.h"


CloseDoorHandler::CloseDoorHandler(Porta p) {
  porta = p;
}

CloseDoorHandler::~CloseDoorHandler() {

}

string CloseDoorHandler::handle() {
  porta.destrancar();
  porta.abrir();

  return Json::StyledWriter.write(CloseDoorHandler::toJson());
}


Json::Value CloseDoorHandler::toJson() {
  Json::Value value(Json::objectValue);
  value["aberta"] = porta.aberta;
  value["trancada"] = porta.trancada;
  return value;
}
