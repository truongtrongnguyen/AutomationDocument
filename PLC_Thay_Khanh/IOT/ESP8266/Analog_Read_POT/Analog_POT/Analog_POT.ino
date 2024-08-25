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

#define phaA D0
#define phaB D2
#define Button D3
#define ButtonV0 V0
#define Led D4
WidgetLED LedV2(V2);
bool buttonState = LOW;
bool LedState = LOW;
int bandau, hientai, value = 0;

int button;

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(phaA, INPUT);
  pinMode(phaB, INPUT);
  pinMode(Button, INPUT_PULLUP);
  pinMode(Led, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  bandau = digitalRead(phaA);
  Blynk.virtualWrite(V1, 123); // Lệnh truyền dữ liệu từ NodeMCU lên app Blynk

}

BLYNK_WRITE(V0){  
  buttonState = param.asInt();
  if(buttonState == HIGH){
    LedState = !digitalRead(Led);
    if(LedState == LOW){
      digitalWrite(Led, LedState);
      LedV2.on();
    }
    else{
    digitalWrite(Led, LedState);
    LedV2.off();

  }
  }
}


void loop()
{
  Blynk.run();

  if(digitalRead(Button) == LOW){
    digitalWrite(Led, !digitalRead(Led));
      delay(300);
      if(digitalRead(Led) == HIGH){
        LedV2.off();
      }
      else{
        LedV2.on();
      }
  }


  hientai = digitalRead(phaA);
  if(hientai != bandau){
    if(digitalRead(phaB) != hientai){
      value++;
      Blynk.virtualWrite(V1, value); // Lệnh truyền dữ liệu từ NodeMCU lên app Blynk
    }
    else{
      value--;
      Blynk.virtualWrite(V1, value); // Lệnh truyền dữ liệu từ NodeMCU lên app Blynk
    }
    Serial.print("Giatri: ");
  Serial.println(value);
  }
  bandau = hientai;
}

