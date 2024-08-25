#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6ZzFklJqh"
#define BLYNK_TEMPLATE_NAME "4RL"
#define BLYNK_AUTH_TOKEN "W6tsEphuVYKwOnJFKFEFOFqxkL7Vg2hI"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nha Bui Quang La";
char pass[] = "0984746299";

#define Led D1

#define Led_In V0
int Value = 0;

void setup() {
  // put your setup code here, to run once:

  // Debug console
  Serial.begin(9600);

  pinMode(Led, OUTPUT);


  digitalWrite(Led, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0){
  Value = param.asInt();
  Value=map(Value, 0, 1500, 0, 255);
  Serial.print("Modify Value: ");
  Serial.println(Value);
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
analogWrite(Led, Value);

}
