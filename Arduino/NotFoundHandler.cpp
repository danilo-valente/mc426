#include "NotFoundHandler.h"

NotFoundHandler::NotFoundHandler() {
}

NotFoundHandler::~NotFoundHandler() {
}

void NotFoundHandler::handle(EthernetClient client, RequestParser& requestParser) {
    JsonObject& json = toJson();
    json.printTo(client);
}

JsonObject& NotFoundHandler::toJson() {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    json["error"] = 404;
    return json;
}
