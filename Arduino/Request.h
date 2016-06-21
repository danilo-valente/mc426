#ifndef REQUEST_H
#define REQUEST_H

#include <map>

enum MethodType
{
  MethodUnknown,
  MethodGet,
  MethodPost
};


class Request {
public:
    String uri;
    MethodType mt;
    map<String, String> params;
    String version;
  	Request(MethodType mt, String uri, map<String, String> params, String version);
  	virtual ~Request();

  	String getParam(String name);
};

#endif /* REQUEST_H */
