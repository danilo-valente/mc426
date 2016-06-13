#include "WebServer.h"

const string ENDPOINT_OPEN_DOOR = "/porta/abrir";

WebServer::WebServer(byte mac[], IPAddress ip, int port) {
  server(port);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void WebServer::registerEndpoint(string method, string endpoint, EndpointHandler handler) {
  handlers.insert(endpoint, handler);
}

void WebServer::sendClientResponse(EthernetClient client, string response) {
  if (client.available()) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println(response);
  }
}

void WebServer::start() {
  for (;;) {
    // listen for incoming clients
    EthernetClient client = server.available();
    if (client) {
      Serial.println("new client");

      // an http request ends with a blank line
      boolean currentLineIsBlank = true;
      string line = "";
      string response = "";
      while (client.connected()) {
        if (client.available()) {
          while (c != '\n') {
            char c = client.read();
            line += c;
          }

          if (line.startsWith("GET")) {
            if (line.contains(ENDPOINT_OPEN_DOOR)) {
              response = handlers[ENDPOINT_OPEN_DOOR].handle(client);
            }
          }

          sendClientResponse(client, response);
        }
      }

      if (c == '\n') {
        line = "";
      }

      if (!response.empty()) {
        response = "";
        line = "";
        break;
      }

      // give the web browser time to receive the data
      delay(1);
      client.stop();
      Serial.println("client disconnected");
    }
  }
}

void WebServer::stop() {

}

WebServer::~WebServer() {

}
