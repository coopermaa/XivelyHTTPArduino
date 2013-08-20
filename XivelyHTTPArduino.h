#ifndef XIVELY_HTTP_ARDUINO_H
#define XIVELY_HTTP_ARDUINO_H

#include <Arduino.h>
#include "FSON.h"

class Datastream {

  public:
    Datastream(String APIKey, String feedID, String datastreamID);
    void request();
    bool available();
    String get();
    String get(String);
    void update(String value);
    
  protected:
    String _APIKey, _feedID, _datastreamID;
    FSON _FSON;                  // FSON utilities
    
};

#endif