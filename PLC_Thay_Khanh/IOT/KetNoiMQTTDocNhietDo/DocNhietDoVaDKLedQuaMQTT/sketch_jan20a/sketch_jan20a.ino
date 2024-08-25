#include<ESP8266WiFi.h>
#include<DHT.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

#define DHTPin D2
const int DHTType = DHT11;
DHT dht(DHTPin, DHTType);
//--------------------------------------------------

const char* ssid = "Nha Bui Quang La";      //Wifi connect
const char* password = "0984746299";   //Password
//--------------------------------------------------

const char* mqtt_server = "56b86445af7d4b66b185b914b51011a1.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_username = "truongtrongnguyenx"; //User
const char* mqtt_password = "TruongNguyen123579"; //Password
//--------------------------------------------------

WiFiClientSecure espClient;
PubSubClient client(espClient);
//--------------------------------------------------

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

const int out[2] = {5,4};
const int btn[2] = {10,12};
unsigned long timeDelay = millis();
const int Led = D0;
boolean updateState = 0;

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

//-----------Call back Method for Receiving MQTT massage and Switch LED---------
void callback(char* topic, byte* payload, unsigned int length) {
  String incommingMessage = "";

  for(int i=0; i<length;i++)
  {
    incommingMessage += (char)payload[i];
  }

  Serial.println("Massage arived ["+String(topic)+"]"+incommingMessage);

  DynamicJsonDocument doc(100);
  DeserializationError error = deserializeJson(doc, incommingMessage);
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  JsonObject obj = doc.as<JsonObject>();
  
  if(obj.containsKey("out1")){
    boolean p = obj["out1"];
    digitalWrite(Led,p);
    Serial.println("out1: "+String(p));
  }
  if(obj.containsKey("out2")){
    boolean p = obj["out2"];
    digitalWrite(out[1],p);
    Serial.println("out2: "+String(p));
  }
  updateState=1;
}
//-----Method for Publishing MQTT Messages---------
void publishMessage(const char* topic, String payload, boolean retained){
  if(client.publish(topic,payload.c_str(),true))
    Serial.println("Message published ["+String(topic)+"]: "+payload);
}

ICACHE_RAM_ATTR void handleBtn(){
  if(millis()-timeDelay>500){
    for(int i=0;i<2;i++){
      if(digitalRead(btn[i])==LOW){
        digitalWrite(out[i],!digitalRead(out[i]));
      }
    }
    updateState=1;
    timeDelay=millis();
  }
}

void setup() {
  Serial.begin(9600);
  while(!Serial) delay(1);

  dht.begin();

  setup_wifi();
  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  for(int i=0; i<2;i++){
    pinMode(out[i],OUTPUT);
    pinMode(btn[i],INPUT_PULLUP);
    attachInterrupt(btn[i],handleBtn,FALLING);
  }
  pinMode(Led,OUTPUT);
  digitalWrite(Led, HIGH);
}
unsigned long timeUpdata=millis();
void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  //read DHT11
  if(millis()-timeUpdata>5000){
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    DynamicJsonDocument doc(1024);
    doc["humidity"]=h;
    doc["temperature"]=t;
    char mqtt_message[128];
    serializeJson(doc,mqtt_message);
    publishMessage("esp8266/dht11", mqtt_message, true);

    timeUpdata=millis();
  }

  if(updateState == 1){
    DynamicJsonDocument doc(1024);
    doc["out1"]=digitalRead(Led);
    doc["out2"]=digitalRead(out[1]);
    char mqtt_message[128];
    serializeJson(doc,mqtt_message);
    publishMessage("esp8266/out", mqtt_message, true);
    updateState=0;
  }
}