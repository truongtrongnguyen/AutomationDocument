#include<ESP8266WiFi.h>
#include<DHT.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

const int DHTPin = D2; // Chân Out của cảm biến nối chân số 5;

const int DHTType = DHT11;
DHT dht(DHTPin, DHTType);
//----Thay đổi thành thông tin của bạn---------------
const char* ssid = "Nha Bui Quang La";      //Wifi connect
const char* password = "0984746299";   //Password

const char* mqtt_server = "56b86445af7d4b66b185b914b51011a1.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_username = "truongtrongnguyenx"; //User
const char* mqtt_password = "TruongNguyen123579"; //Password
//--------------------------------------------------
WiFiClientSecure espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//------------Connect to MQTT Broker-----------------------------
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientID =  "ESPClient-";
    clientID += String(random(0xffff),HEX);
    if (client.connect(clientID.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("esp8266/client");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
//-----Call back Method for Receiving MQTT massage---------
void callback(char* topic, byte* payload, unsigned int length) {
  String incommingMessage = "";
  for(int i=0; i<length;i++) incommingMessage += (char)payload[i];
  Serial.println("Massage arived ["+String(topic)+"]"+incommingMessage);
}
//-----Method for Publishing MQTT Messages---------
void publishMessage(const char* topic, String payload, boolean retained){
  if(client.publish(topic,payload.c_str(),true))
    Serial.println("Message published ["+String(topic)+"]: "+payload);
}


void setup() {
  Serial.begin(9600);
  while(!Serial) delay(1);

  setup_wifi();
  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  dht.begin(); // Khởi động cảm biến
}
unsigned long timeUpdata=millis();
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  if(Serial.available())
  {
    
  }
  client.loop();
  //read DHT11
  if(millis()-timeUpdata>1000){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print("temperature: "); 
    Serial.println(t);
    Serial.print("humidity: ");
     Serial.println(h);


    DynamicJsonDocument doc(1024);
    doc["humidity"]=h;
    doc["temperature"]=t;
    char mqtt_message[128];
    serializeJson(doc,mqtt_message);
    publishMessage("esp8266/dht11", mqtt_message, true);

    timeUpdata=millis();
  }
}
