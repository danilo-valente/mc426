#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

#include <map>
#include <string>
#include <regex>
#include <cstring>
#include <iostream>
#include <Ethernet>

#include "Request.h"

#define STRING_BUFFER_SIZE 128

typedef char BUFFER[STRING_BUFFER_SIZE];

class RequestParser {
public:
    Request& parse(EthernetClient& client);
  	RequestParser();
  	virtual ~RequestParser();
private:
    void getNextHttpLine(EthernetClient& client, BUFFER& readBuffer);
};

#endif /* REQUEST_PARSER_H */
