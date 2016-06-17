#include "TurnOnLightHandler.h"


TurnOnLightHandler::TurnOnLightHandler(Lampada l) {
  lampada = l;
}

TurnOnLightHandler::~TurnOnLightHandler() {

}

string TurnOnLightHandler::handle() {
  lampada.acender();

  return Json::StyledWriter.write(TurnOnLightHandler::toJson());
}


Json::Value TurnOnLightHandler::toJson() {
  Json::Value value(Json::objectValue);
  value["acessa"] = lampada.acesa;
  return value;
}
