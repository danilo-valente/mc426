#ifndef AUTH_HANDLER_H
#define AUTH_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"
#include "User.h"

#define MAX_USERS 1

class AuthHandler : public EndpointHandler {
private:
    User *users[MAX_USERS];
    uint8_t count;
public:
    AuthHandler();
    virtual ~AuthHandler();
    virtual void addUser(User *user);
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson(uint8_t token);
};

#endif /* AUTH_HANDLER_H */
