#ifndef ENDPOINT_HANDLER_H_
#define ENDPOINT_HANDLER_H_

#include <ArduinoJson.h>

#include "RequestParser.h"

class EndpointHandler {
public:
    virtual void handle(EthernetClient client, RequestParser& requestParser) = 0;
};

#endif /* ENDPOINT_HANDLER_H_ */
