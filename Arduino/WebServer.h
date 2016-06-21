#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <ArduinoJson.h>
#include <Ethernet.h>
#include <EthernetServer.h>

#include "Device.h"
#include "EndpointHandler.h"
#include "NotFoundHandler.h"

#define MAX_ENDPOINTS 20
#define ENDPOINT_NOT_FOUND ((uint8_t) -1)

class WebServer : Device {
private:
    String endpoints[MAX_ENDPOINTS];
    EndpointHandler *handlers[MAX_ENDPOINTS];
    uint8_t count;
    byte *mac;
    IPAddress ip;
    EthernetServer *server;
    NotFoundHandler notFoundHandler;
    uint8_t findHandler(String& request);
public:
    WebServer(uint16_t port, byte *mac, IPAddress ip);
    virtual ~WebServer();
    void registerHandler(String endpoint, EndpointHandler *handler);
    void setup();
    void loop();
protected:
    void empty(String& str);
};

#endif /* WEBSERVER_H */
