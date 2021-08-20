//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "demo1-215c7.firebaseio.com"
#define FIREBASE_AUTH "2naW0VphLeVzvM9Pssf1Vg6QMXYgNtBWTgM0TdoR"
#define WIFI_SSID "IKARUS1"
#define WIFI_PASSWORD "ikarus.123"

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  server.begin();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
  int pinStatus = Firebase.getInt("LED");
  digitalWrite(LED_BUILTIN, pinStatus == 0 ? HIGH : LOW);
  Serial.print("LED Status: ");
  Serial.println(pinStatus == 0 ? HIGH : LOW);
 // Firebase.setInt("LED", pinStatus);
 // Serial.print("Pin Status: ");
 // Serial.println(pinStatus);
  delay(500);

  // Check if a client has connected
//  WiFiClient client = server.available();
//  if (!client) {
//    return;
//  }
//  Serial.println(F("new client"));
//
//  client.setTimeout(5000); // default is 1000
//
//  // Read the first line of the request
//  String req = client.readStringUntil('\r');
//  Serial.println(F("request: "));
//  Serial.println(req);
//
//  // Match the request
//  int val;
//  if (req.indexOf(F("/gpio/0")) != -1) {
//    val = 0;
//  } else if (req.indexOf(F("/gpio/1")) != -1) {
//    val = 1;
//  } else {
//    Serial.println(F("invalid request"));
//    val = digitalRead(LED_BUILTIN);
//  }
//
//  // Set LED according to the request
//  digitalWrite(LED_BUILTIN, val);
//
//  // read/ignore the rest of the request
//  // do not client.flush(): it is for output only, see below
//  while (client.available()) {
//    // byte by byte is not very efficient
//    client.read();
//  }
//
//  // Send the response to the client
//  // it is OK for multiple small client.print/write,
//  // because nagle algorithm will group them into one single packet
//  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now "));
//  client.print((val) ? F("high") : F("low"));
//  client.print(F("<br><br>Click <a href='http://"));
//  client.print(WiFi.localIP());
//  client.print(F("/gpio/1'>here</a> to switch LED GPIO on, or <a href='http://"));
//  client.print(WiFi.localIP());
//  client.print(F("/gpio/0'>here</a> to switch LED GPIO off.</html>"));
//
//  // The client will actually be *flushed* then disconnected
//  // when the function returns and 'client' object is destroyed (out-of-scope)
//  // flush = ensure written data are received by the other side
//  Serial.println(F("Disconnecting from client"));
}
