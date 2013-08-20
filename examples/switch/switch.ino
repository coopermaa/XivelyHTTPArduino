// Toggle led
#include <XivelyHTTPArduino.h>

// Change this for your API key (from your account dashboard)
String APIKey = "FzZOVUxKRPl_Tvvtr1z77b8gOVCSAKxlTnlwSzQrZ3U4MD0g";

// Change these for your feed and datastream
String feed_id = "79650";
String datastream_id = "lights";
Datastream datastream(APIKey, feed_id, datastream_id);

long lastRequestTime = 0;
const int INTERVAL = 2000; // update interval, in miliseconds
const int led = 9;

void setup() {
  Serial.begin(57600);
  pinMode(led, OUTPUT);
}

void loop() {   
  if ((millis() - lastRequestTime) > INTERVAL) {
    datastream.request();
    lastRequestTime = millis();    
  }
    
  if (datastream.available()) {
     String state = datastream.get();
     if (state == "\"1\"") {
       digitalWrite(led, HIGH);
     } else {
       digitalWrite(led, LOW);
     }  
  }
}


