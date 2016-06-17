#include "TurnOffLightHandler.h"


TurnOffLightHandler::TurnOffLightHandler(Lampada l) {
  lampada = l;
}

TurnOffLightHandler::~TurnOffLightHandler() {

}

string TurnOffLightHandler::handle() {
  lampada.apagar();

  return Json::StyledWriter.write(TurnOffLightHandler::toJson());
}


Json::Value TurnOffLightHandler::toJson() {
  Json::Value value(Json::objectValue);
  value["acesa"] = lampada.acesa;
  return value;
}
