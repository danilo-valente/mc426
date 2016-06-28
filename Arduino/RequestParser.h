#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

#include <Arduino.h>

class RequestParser {
private:
    String request;
public:
  	RequestParser();
  	virtual ~RequestParser();
    void setRequest(String& request);
    String get(const char *param);
    String get(String& param);
};

#endif /* REQUEST_PARSER_H */
