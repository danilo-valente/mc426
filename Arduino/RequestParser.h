#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

using namespace std;
#include <string>
#include <cstring>


class RequestParser {
public:
    string parse(string& param);
  	RequestParser(char* request);
  	virtual ~RequestParser();
private:
    char* request;
};

#endif /* REQUEST_PARSER_H */
