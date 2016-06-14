#include "OpenDoorHandler.h"


OpenDoorHandler::OpenDoorHandler(Porta p) {
  porta = p;
}

OpenDoorHandler::~OpenDoorHandler() {

}

string OpenDoorHandler::handle() {
  porta.destrancar();
  porta.abrir();

  return Json::StyledWriter.write(OpenDoorHandler::toJson());
}


Json::Value OpenDoorHandler::toJson() {
  Json::Value value(Json::objectValue);
  value["aberta"] = porta.aberta;
  value["trancada"] = porta.trancada;
  return value;
}
