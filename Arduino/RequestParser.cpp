#include "RequestParser.h"

// Read the first line of the HTTP request, setting Uri Index and returning the method type.
// If it is a GET method then we set the requestContent to whatever follows the '?'. For a other
// methods there is no content except it may get set later, after the headers for a POST method.
Request& RequestParser::readRequestLine(EthernetClient& client)
{
  MethodType eMethod;
  BUFFER readBuffer;
  // Get first line of request:
  // Request-Line = Method SP Request-URI SP HTTP-Version CRLF
  getNextHttpLine(client, readBuffer);

  char pSpDelimiters[] = " \r\n";

  // Split it into the 3 tokens
  char * pMethod  = strtok(readBuffer, pSpDelimiters);
  char * pUri     = strtok(NULL, pSpDelimiters);
  char * pVersion = strtok(NULL, pSpDelimiters);
  map<string, string> params;

  strtok(pUri, "?");
  char * pQuery   = strtok(NULL, "?");
  if (pQuery != NULL)
  {
    string query = string(pQuery);
    regex pattern("([\\w+%]+)=([^&]*)");
    auto words_begin = sregex_iterator(query.begin(), query.end(), pattern);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; i++)
    {
        string key = (*i)[1].str();
        string value = (*i)[2].str();
        params[key] = value;
    }
  }

  if (strcmp(pMethod, "GET") == 0)
    eMethod = MethodGet;
  else if (strcmp(pMethod, "POST") == 0)
    eMethod = MethodPost;
  else
    eMethod = MethodUnknown;

  return new Request(eMethod, string(pUri), params, string(version));
}

/**********************************************************************************************************************
* Read the next HTTP header record which is CRLF delimited.  We replace CRLF with string terminating null.
***********************************************************************************************************************/
void RequestParser::getNextHttpLine(EthernetClient & client, BUFFER & readBuffer)
{
  char c;
  int bufindex = 0; // reset buffer

  // reading next header of HTTP request
  if (client.connected() && client.available())
  {
    // read a line terminated by CRLF
    readBuffer[0] = client.read();
    readBuffer[1] = client.read();
    bufindex = 2;
    for (int i = 2; readBuffer[i - 2] != '\r' && readBuffer[i - 1] != '\n'; ++i)
    {
      // read full line and save it in buffer, up to the buffer size
      c = client.read();
      if (bufindex < sizeof(readBuffer))
        readBuffer[bufindex++] = c;
    }
    readBuffer[bufindex - 2] = 0;  // Null string terminator overwrites '\r'
  }
}
