/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  NOTE: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6ZzFklJqh"
#define BLYNK_TEMPLATE_NAME "4RL"
#define BLYNK_AUTH_TOKEN "W6tsEphuVYKwOnJFKFEFOFqxkL7Vg2hI"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nha Bui Quang La";
char pass[] = "0984746299";

#define relay D0
WidgetLED led(V0);  // Lệnh khai báo biến ảo trên Blynk
int button;

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(relay, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Hàm truyền và nhận dữ liệu từ App Blynk trên điện thoại
BLYNK_WRITE(V1){
  button = param.asInt();
  if(button == 1){
    digitalWrite(relay, LOW);
    led.on(); // Lệnh bật ON/OFF Led trên app Blynk
  }
  else{
    digitalWrite(relay, HIGH);
    led.off();
  }
}



void loop()
{
  Blynk.run();
}

