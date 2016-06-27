#include "RequestParser.h"

RequestParser::RequestParser(char* request) : request(request) {

}

string RequestParser::parse(string& param) {
    strtok(this->request, " ");
    char* pUri = strtok(NULL, " ");

    strtok(pUri, "?");
    char* pQuery = strtok(NULL, "?");

    string value;
    char* itemChar = strtok(pQuery, "&");

    while (itemChar != NULL) {
        string item = itemChar;
        int separator = item.find("=");

        string name = item.substr(0, separator);
        if (name.compare(param) == 0) {
            value = item.substr(separator + 1, name.length());
            break;
        }
        itemChar = strtok(NULL, "&");
    }

    return value;
}


RequestParser::~RequestParser() {
}
