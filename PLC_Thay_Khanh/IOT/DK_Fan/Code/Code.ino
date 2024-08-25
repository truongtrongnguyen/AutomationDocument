#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL66bv7nGww"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "yEw59dSWT0tfRhL2AYbP6zN1pHXgueXc"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nha Bui Quang La";
char pass[] = "0984746299";

#define FanL_Out D3
#define FanN_Out D4
#define L D1
#define N D2
#define Ngat D2

#define Fan1_In V3
#define Fan2_In V4
#define Fan3_In V0
#define DeleteDelay V1
#define Fan_Test V2

bool Status_Fan;
bool Status_Fan1;
bool StatusCurrent;
bool StatusCurrent1;
bool StatusCurrent2;  
bool StatusDelete;

int Mode = 0;
unsigned long TimeDelay = 60000;
unsigned long thoigian;
unsigned long hientai = 0;
int Count = 0;

void setup() {
  // put your setup code here, to run once:

  // Debug console
  Serial.begin(9600);

  pinMode(FanL_Out, OUTPUT);
  pinMode(FanN_Out, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(N, OUTPUT);
  pinMode(Ngat, OUTPUT);


  digitalWrite(FanL_Out, HIGH);
  digitalWrite(FanN_Out, HIGH);
  digitalWrite(L, LOW);
  digitalWrite(N, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

// attachInterrupt(digitalPinToInterrupt(StatusDelete), OffFan, CHANGE);
attachInterrupt(digitalPinToInterrupt(Ngat), OffFan, FALLING);
}
 ICACHE_RAM_ATTR  void  OffFan(){
  Serial.println("Motion was detected");
  digitalWrite(FanL_Out, HIGH);
  digitalWrite(FanN_Out, HIGH);

  Mode = 0;
  StatusCurrent1 = LOW;
  StatusCurrent2 = LOW;
  TimeDelay = 0;
}

BLYNK_WRITE(V1){
  StatusDelete = param.asInt();
  if(StatusDelete == HIGH){
  Serial.print("Ngat ngoai: ");
  Serial.println(StatusDelete);
  StatusCurrent1 = HIGH;
  OffFan();
  TimeDelay = 0;
  }
}

BLYNK_WRITE(V3){
  Status_Fan = param.asInt();
  if(Status_Fan == HIGH && Mode == 0)
  {
    digitalWrite(FanL_Out, LOW);
    digitalWrite(FanN_Out, LOW);

    Serial.print("Bat Quat V3: ");   Serial.print(FanL_Out);  Serial.println(FanN_Out);
    Mode = 1;
    Serial.println("Bat Quat V3"); 
  }
  else{
    digitalWrite(FanL_Out, HIGH);
    digitalWrite(FanN_Out, HIGH);

    Mode = 0;
    Serial.println("Tat Quat V3"); 
  }
}

BLYNK_WRITE(V4){  
  Status_Fan1 = param.asInt();
  if(Status_Fan1 == HIGH && Mode == 0){
  TimeDelay = 1800000;
     StatusCurrent = !digitalRead(FanL_Out);
      Serial.println("Bat Quat V4");  
      digitalWrite(FanL_Out, LOW);
      digitalWrite(FanN_Out, LOW);

      Serial.println("Da bat quat");
      delay(TimeDelay);
      OffFan();
      Serial.println("Da Tat quat");
    }
  }
  BLYNK_WRITE(V0){  
  Status_Fan1 = param.asInt();
  if(Status_Fan1 == HIGH && Mode == 0){
  TimeDelay = 3600000;
     StatusCurrent = !digitalRead(FanL_Out);
      Serial.println("Bat Quat V4");  
      digitalWrite(FanL_Out, LOW);
      digitalWrite(FanN_Out, LOW);

      Serial.println("Da bat quat");
      delay(TimeDelay);
      OffFan();
      Serial.println("Da Tat quat");
    }
  }

  BLYNK_WRITE(V2){  
  Status_Fan1 = param.asInt();
  if(Status_Fan1 == HIGH && Mode == 0){
  TimeDelay = 10000;
     StatusCurrent = !digitalRead(FanL_Out);
      Serial.println("Bat Quat V4");  
      digitalWrite(FanL_Out, LOW);
      digitalWrite(FanN_Out, LOW);

      Serial.println("Da bat quat");
      delay(TimeDelay);
      OffFan();
      Serial.println("Da Tat quat");
    }
  }

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
  thoigian = millis();


if(StatusCurrent1 == HIGH)
        {
          OffFan();
          StatusCurrent1 = LOW;
        }

}
