#include "AuthHandler.h"

AuthHandler::AuthHandler() {
    this->count = 0;
}

AuthHandler::~AuthHandler() {
}

void AuthHandler::addUser(User *user) {
    this->users[this->count++] = user;
}

void AuthHandler::handle(EthernetClient client, RequestParser& requestParser) {
    String username = requestParser.get("u");
    String password = requestParser.get("p");

    uint8_t i = 0;
    while (i < this->count && (this->users[i]->username != username || this->users[i]->password != password)) {
        i++;
    }

    Serial.println("Trying to authenticate using username " + username + " and password " + password);

    JsonObject& json = toJson(i);
    json.printTo(client);
}

JsonObject& AuthHandler::toJson(uint8_t index) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &json = jsonBuffer.createObject();
    if (index < this->count) {
        json["success"] = true;
        json["token"] = index;
        json["name"] = this->users[index]->name;
    } else {
        json["success"] = false;
        json["error"] = 401;
    }
    return json;
}
