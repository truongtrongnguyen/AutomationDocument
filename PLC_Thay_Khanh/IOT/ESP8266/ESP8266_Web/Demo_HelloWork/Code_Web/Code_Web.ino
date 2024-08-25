#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

// Your WiFi credentials.
// Set password to "" for open networks.
const char* ssid = "Nha Bui Quang La";
const char* password = "0984746299";

const char text[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
   <style type="text/css">
      button {
         background-color: #4CAF50; /* Màu nền */
         color: white; /* Màu chữ */
         padding: 14px 20px; /* Đệm bên trong */
         margin: 8px 0; /* Lề bên ngoài */
         border: none; /* Không viền */
         cursor: pointer; /* Con trỏ chuột */
         width: 100%; /* Chiều rộng */
      }

      button:hover {
         opacity: 0.8; /* Độ mờ khi rê chuột lên nút */
      }
   </style>
</head>
<body>
   <button type="button"><a href="/OnLed">On/Off</a></button>
</body>
</html>
)=====";


#define led D4

void setup() {
  // put your setup code here, to run once:

  // Debug console
    pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
    Serial.begin(115200);
    Serial.println("Begin Connect to WiFi");
     WiFi.begin(ssid, password);
     Serial.println("Connect to WiFi");

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

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

//IP address: 192.168.1.68
server.on("/", handleRoot);
//IP address: 192.168.1.68/OnLed
server.on("/OnLed", OnLed);
server.on("/OnLed1", OnLed1);
//IP address: 192.168.1.68/inline
server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

server.onNotFound(handleNotFound);
server.begin();
Serial.println("HTTP server started");

}

void OnLed(){
  
  digitalWrite(led, !digitalRead(led));
  delay(1000);
  handleRoot();
}

void OnLed1(){
  
  digitalWrite(led, !digitalRead(led));
}

void handleRoot() {


String texthtml = text;

  server.send(200, "text/html", texthtml);
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}



void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}
