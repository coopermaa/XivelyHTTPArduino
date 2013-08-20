#include "XivelyHTTPArduino.h"

static String LF = "\x0A";
static String API_HOST = "api.xively.com";

static String headerGet = "Host: " + API_HOST + LF
 + "Pragma: no-cache" + LF
 + "Connection: keep-alive"; 

static String headerPut = "Host: " + API_HOST + LF
 + "Content-Type: application/json; charset=utf-8" + LF 
 + "Connection: keep-alive";  

Datastream::Datastream(String APIKey, String feedID, String datastreamID)
{
  _APIKey = APIKey;
  _feedID = feedID;
  _datastreamID = datastreamID;
}

void Datastream::request()
{
  _FSON.initStreamScanner();
   
  String requestLine = "GET /v2/feeds/" + _feedID + "/datastreams/" + _datastreamID + " HTTP/1.1";
  
  Serial.println(requestLine);  
  Serial.println(headerGet);
  Serial.println("X-APiKey: " + _APIKey);
  Serial.println("");
}

bool Datastream::available()
{
  while (Serial.available()) {
    char c = Serial.read();    
    bool found = _FSON.setStreamedObject(c);
    if (found) {
      return found;
    }
  } 
  
  return false;
}

String Datastream::get()
{
  return (_FSON.getProperty("current_value"));
}

String Datastream::get(String propertyName)
{  
  return (_FSON.getProperty(propertyName));
}

void Datastream::update(String value)
{
  _FSON.initStreamScanner();
  String body = "{ \"current_value\": " + value + " }";

   
  String requestLine = "PUT /v2/feeds/" + _feedID + "/datastreams/" 
                     + _datastreamID + " HTTP/1.1";
  
  Serial.println(requestLine);
  Serial.println(headerPut);
  Serial.println("X-APiKey: " + _APIKey);
  Serial.print("Content-Length: "); Serial.println(body.length());
  Serial.println("");
  Serial.println(body);  
}