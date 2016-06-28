#include "WebServer.h"

#define BUFFER_SIZE 32

WebServer::WebServer(uint16_t port, const uint8_t mac[], IPAddress ip) : mac(mac), ip(ip) {
    server = new EthernetServer(port);
    count = 0;
}

WebServer::~WebServer() {
}

void WebServer::registerHandler(const char *endpoint, EndpointHandler *handler) {
    endpoints[count] = endpoint;
    handlers[count] = handler;
    count++;
}

void WebServer::setup() {
    Ethernet.begin((uint8_t *) mac, ip);
    server->begin();
    Serial.print("Server running at ");
    Serial.println(Ethernet.localIP());
}

void WebServer::loop() {
    
    EthernetClient client = server->available();
    if (client) {
        EndpointHandler *handler = &notFoundHandler;
        bool currentLineIsBlank = true;
        bool ignore = false;
        String line;
        empty(line);
        
        while (client.connected()) {
            if (client.available()) {

                char c = client.read();
                if (c == '\n') {
                    if (line.startsWith("GET")) {
                        Serial.println(line);
                        this->requestParser.setRequest(line);
                        
                        client.println("HTTP/1.1 200 OK");
                        client.println("Connection: close");
                        client.println("Content-Type: application/json");
                        client.println("Access-Control-Allow-Origin: *");
                        client.println();
                        
                        uint8_t i = findHandler(line);
                        if (i != ENDPOINT_NOT_FOUND) {
                            handler = handlers[i];
                        }
                    }

                    if (currentLineIsBlank) {
                        handler->handle(client, this->requestParser);
                        break;
                    }

                    currentLineIsBlank = true;
                    ignore = false;
                    empty(line);
                } else if (c != '\r') {
                    currentLineIsBlank = false;
                    
                    if (line.length() == 3) {
                        ignore = !line.startsWith("GET");
                    }

                    if (!ignore) {
                        line += c;
                    }
                }
            }
        }

        delay(1);
        client.stop();
    }
}

uint8_t WebServer::pin() {
    return (uint8_t) -1;
}

uint8_t WebServer::type() {
    return Device::WEB_SERVER;
}

void WebServer::empty(String& str) {
    str = String();
    if (!str.reserve(BUFFER_SIZE)) {
        Serial.println("Error: not enought memory");
    }
}

uint8_t WebServer::findHandler(String& request) {
    for (uint8_t i = 0; i < count; i++) {
        if (request.indexOf(endpoints[i]) == 5) {
            return i;
        }
    }

    return ENDPOINT_NOT_FOUND;
}
