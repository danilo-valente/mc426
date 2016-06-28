#ifndef NOT_FOUND_HANDLER_H
#define NOT_FOUND_HANDLER_H

#include <Ethernet.h>
#include <ArduinoJson.h>

#include "EndpointHandler.h"
#include "RequestParser.h"

class NotFoundHandler : public EndpointHandler {
public:
    NotFoundHandler();
    virtual ~NotFoundHandler();
    virtual void handle(EthernetClient client, RequestParser& requestParser);
    virtual JsonObject& toJson();
};

#endif /* NOT_FOUND_HANDLER_H */
