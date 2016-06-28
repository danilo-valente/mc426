#include "RequestParser.h"

RequestParser::RequestParser() {
    this->request = "";
}

RequestParser::~RequestParser() {
}

void RequestParser::setRequest(String& request) {
    this->request = request;
}

String RequestParser::get(const char *param) {
    String p = param;
    return this->get(p);
}

String RequestParser::get(String& param) {
    int16_t i, j, k;
    
    i = this->request.indexOf('?');
    if (i != -1) {
        j = this->request.indexOf('?' + param + '=', i);
        if (j == -1) {
            j = this->request.indexOf('&' + param + '=', i);
        }

        if (j != -1) {
            j += param.length() + 2;
            k = this->request.indexOf('&', j);
            if (k == -1) {
                k = this->request.indexOf(' ', j);
            }

            return this->request.substring(j, k);
        }
    }

    return "";
}
