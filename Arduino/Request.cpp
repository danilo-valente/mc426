#include "Request.h"


Request::Request(MethodType mt, String uri, map<String, String> params, String version) :
  mt(mt), uri(uri), params(params), version(version) {

}


Request::~Request() {

}


String Request::getParam(String name) {
    this->params[name];
}
