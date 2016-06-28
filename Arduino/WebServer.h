#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <ArduinoJson.h>
#include <Ethernet.h>
#include <EthernetServer.h>

#include "Device.h"
#include "RequestParser.h"
#include "EndpointHandler.h"
#include "NotFoundHandler.h"

#define MAX_ENDPOINTS 10
#define ENDPOINT_NOT_FOUND ((uint8_t) -1)

class WebServer : Device {
private:
    const char *endpoints[MAX_ENDPOINTS];
    EndpointHandler *handlers[MAX_ENDPOINTS];
    uint8_t count;
    const uint8_t *mac;
    IPAddress ip;
    EthernetServer *server;
    RequestParser requestParser;
    NotFoundHandler notFoundHandler;
    
    uint8_t findHandler(String& request);
public:
    WebServer(uint16_t port, const uint8_t *mac, IPAddress ip);
    virtual ~WebServer();
    void registerHandler(const char *endpoint, EndpointHandler *handler);
    
    void setup();
    void loop();
    uint8_t pin();
    uint8_t type();
protected:
    void empty(String& str);
};

#endif /* WEBSERVER_H */
