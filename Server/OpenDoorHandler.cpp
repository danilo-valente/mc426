#include "OpenDoorHandler.h"


OpenDoorHandler::OpenDoorHandler(Porta p) {
  porta = porta;
}

OpenDoorHandler::~OpenDoorHandler() {

}

string OpenDoorHandler::handle(map<string, string> params, EthernetClient client) {
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
