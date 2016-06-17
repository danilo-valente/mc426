using namespace std;

#include <map>
#include <string>
#include <json/json.h>
#include <Ethernet>

#ifndef WEBSERVER_H_
#define WEBSERVER_H_

class WebServer {
public:
  WebServer(byte mac[], IPAddress ip, int port);
  virtual ~WebServer();
  void registerEndpoint(string method, string endpoint, EndpointHandler handler);
  void start();
  void stop();
  void sendClientResponse(EthernetClient client, string response);

  EthernetServer server;
  map<string, EndpointHandler> handlers;
};

#endif /* WEBSERVER_H_ */
