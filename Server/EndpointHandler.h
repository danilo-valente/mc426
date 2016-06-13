using namespace std;
#include <map>
#include <string>
#include <Ethernet.h>

#ifndef ENDPOINT_HANDLER_H_
#define ENDPOINT_HANDLER_H_

class EndpointHandler {
public:
  virtual string handle(EthernetClient client);
  virtual string toJson();
};

#endif /* ENDPOINT_HANDLER_H_ */
