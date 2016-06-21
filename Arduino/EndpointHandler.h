#ifndef ENDPOINT_HANDLER_H_
#define ENDPOINT_HANDLER_H_

#include <ArduinoJson.h>

class EndpointHandler {
public:
    virtual void handle(EthernetClient client) = 0;
    virtual JsonObject& toJson() = 0;
};

#endif /* ENDPOINT_HANDLER_H_ */
