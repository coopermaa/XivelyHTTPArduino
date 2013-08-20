// Send a random temperature to xively every 5 seconds
// Demo UI: http://bit.ly/19uUXiL
#include <XivelyHTTPArduino.h>

// Change this for your API key (from your account dashboard)
String APIKey = "FzZOVUxKRPl_Tvvtr1z77b8gOVCSAKxlTnlwSzQrZ3U4MD0g";

// Change these for your feed and datastream
String feed_id = "79650";
String datastream_id = "temperature";
Datastream datastream(APIKey, feed_id, datastream_id);

void setup() {
  Serial.begin(57600);
  
  randomSeed(analogRead(0));
}

void loop() {
  delay(5000);  
  
  int temperature = random(10, 20);
  String value = String(temperature);
  datastream.update(value);
}



