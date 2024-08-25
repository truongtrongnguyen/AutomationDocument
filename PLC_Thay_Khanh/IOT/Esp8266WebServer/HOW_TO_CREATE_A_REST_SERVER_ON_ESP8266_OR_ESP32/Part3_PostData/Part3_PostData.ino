/*
 *  Json parametric POST REST request with ArduinoJSON library
  *  by Mischianti Renzo <https://mischianti.org>
 *
 *  https://mischianti.org/
 *  https://mischianti.org/how-to-create-a-rest-server-on-esp8266-or-esp32-post-put-patch-delete-part-3/
 */
 
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
 
char ssid[] = "Nha Bui Quang La";
char pass[] = "0984746299";

#define Led D0
 
ESP8266WebServer server(80);
 
// Serving Hello world
void setRoom() {
    String postBody = server.arg("plain");
    Serial.println(postBody);
 
    DynamicJsonDocument doc(512);
    DeserializationError error = deserializeJson(doc, postBody);
    if (error) {
        // if the file didn't open, print an error:
        Serial.print(F("Error parsing JSON "));
        Serial.println(error.c_str());
 
        String msg = error.c_str();
 
        server.send(400, F("text/html"),
                "Error in parsin json body! <br>" + msg);
 
    } else {
        JsonObject postObj = doc.as<JsonObject>();
 
        Serial.print(F("HTTP Method: "));
        Serial.println(server.method());
 
        if (server.method() == HTTP_POST) {
            if (postObj.containsKey("name") && postObj.containsKey("type")) {
 
                Serial.println(F("done."));
 
                // Here store data or doing operation
 
 
                // Create the response
                // To get the status of the result you can get the http status so
                // this part can be unusefully
                DynamicJsonDocument doc(512);
                doc["status"] = "OK";
 
                Serial.print(F("Stream..."));
                String buf;
                serializeJson(doc, buf);
 
                server.send(201, F("application/json"), buf);
                Serial.print(F("done."));
 
            }else {
                DynamicJsonDocument doc(512);
                doc["status"] = "KO";
                doc["message"] = F("No data found, or incorrect!");
 
                Serial.print(F("Stream..."));
                String buf;
                serializeJson(doc, buf);
 
                server.send(400, F("application/json"), buf);
                Serial.print(F("done."));
            }
        }
    }
}
 
 
// Define routing
void restServerRouting() {
    server.on("/", HTTP_GET, []() {
        server.send(200, F("text/html"),
            F("Welcome to the REST Web Server"));
            Serial.println("Computer Access");
    });
    // handle post request
    server.on(F("/setRoom"), HTTP_POST, setRoom);
}
 
// Manage not found URL
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
 
void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.println("");

  pinMode(Led, OUTPUT);
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  // Activate mDNS this is used to be able to connect to the server
  // with local DNS hostmane esp8266.local
  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }
 
  // Set server routing
  restServerRouting();
  // Set not found response
  server.onNotFound(handleNotFound);
  // Start server
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void) {
  server.handleClient();

  digitalWrite(Led, HIGH);
  delay(500);
  digitalWrite(Led, LOW);
  delay(500);
}