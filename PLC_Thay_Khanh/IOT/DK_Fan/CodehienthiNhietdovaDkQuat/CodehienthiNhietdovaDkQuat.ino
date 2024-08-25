#include<DHT.h> // Thư viện Nhiệt độ độ ẩm
#include <Wire.h> // Gọi thư viện I2c để sử dụng các thư viện có sẵn
#include <LiquidCrystal_I2C.h> // Thư viện LCD I2C

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
#define ChargerL_Out D6
#define ChargerN_Out D7
#define Ngat D0

#define Fan1_In V3
#define Fan2_In V4
#define Fan3_In V0
#define DeleteDelay V1
#define Fan_Test V2

bool Status_Fan;
bool StatusButtonBlynk;
bool StatusCurrent;
bool StatusCurrent1;
bool StatusCurrent2;  
bool StatusDelete;

int ModeFan = 0;
int ModeCharger = 0;
unsigned long TimeFanDelay = 0;
int TimeRead = 1000;
int TimeFanDisplayed = 0;
int TimeChargerDisplayed = 0;
unsigned long CurrentRead = 0;
unsigned long thoigian;
unsigned long CurrentFanTime = 0;
unsigned long CurrentChargerTime = 0;
int StartedFan = 0;
int StartedCharger = 0;
int TimeChargerDelay = 0;
float Count = 0;

LiquidCrystal_I2C lcd(0x27,16,2); //Khai báo địa chỉ I2C (0x27 or 0x3F) và LCD 16x02

const int DHTPin = D5; // Chân Out của cảm biến nối chân số 5;

const int DHTType = DHT11; // Khai báo kiểu cảm biến là loại DHT11

DHT dht(DHTPin, DHTType); // Khai báo thư viện chân cảm biến và kiểu cảm biến

float Temperature_C = 0;  // Nhiệt độ C
float Humidity = 0; // Độ ẩm
float Temperature_F = 0;  // Nhiệt độ F

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
    Wire.begin(D2, D1);
   lcd.init(); //Khởi tạo màn hình LCD
   lcd.backlight(); // Bật màn hình LCD
   lcd.clear();
   lcd.setCursor(0, 0);
    lcd.println(" Hello Work    ");
    lcd.setCursor(0, 1);
    lcd.print("Well Come To You");
    delay(1000);
    lcd.clear();

   dht.begin(); // Khởi động cảm biến

  pinMode(FanL_Out, OUTPUT);
  pinMode(FanN_Out, OUTPUT);
  pinMode(ChargerL_Out, OUTPUT);
  pinMode(ChargerN_Out, OUTPUT);

  pinMode(Ngat, OUTPUT);

  digitalWrite(FanL_Out, HIGH);
  digitalWrite(FanN_Out, HIGH);
  digitalWrite(ChargerL_Out, HIGH);
  digitalWrite(ChargerN_Out, HIGH);

  delay(200);



  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.write("TT Connect Blynk: ");
  Serial.write(Blynk.connected());

  if(Blynk.connected())
  {
    digitalWrite(FanL_Out, LOW);
    digitalWrite(FanN_Out, LOW);
    digitalWrite(ChargerL_Out, LOW);
    digitalWrite(ChargerN_Out, LOW);
  }
  

// attachInterrupt(digitalPinToInterrupt(StatusDelete), OffFan, CHANGE);
attachInterrupt(digitalPinToInterrupt(Ngat), OffFanInterrupt, FALLING);
}

// Interrupt
 ICACHE_RAM_ATTR  void  OffFanInterrupt(){
   OffFan();

  OffCharger();
}

void  OffFan(){
  Serial.println("Motion was detected");
  digitalWrite(FanL_Out, LOW);
  digitalWrite(FanN_Out, LOW);
  TimeFanDelay = 0;
  TimeFanDisplayed = 0;
  StartedFan = 0;
  ModeFan = 0;
}

void  OffCharger(){
  Serial.println("Motion was detected OffCharger");
  digitalWrite(ChargerL_Out, LOW);
  digitalWrite(ChargerN_Out, LOW);
  TimeChargerDelay = 0;
  TimeChargerDisplayed = 0;
  StartedCharger = 0;
  ModeCharger = 0;
}

BLYNK_WRITE(V1){
  StatusDelete = param.asInt();
  if(StatusDelete == HIGH){
  Serial.print("Ngat ngoai: "); Serial.println(StatusDelete);
  OffFanInterrupt();
  }
}

// On/Off
BLYNK_WRITE(V3){
  Status_Fan = param.asInt();
  if(Status_Fan == HIGH && ModeFan == 0)
  {
    digitalWrite(FanL_Out, HIGH);
    digitalWrite(FanN_Out, HIGH);
    TimeFanDisplayed = 1;
    Serial.print("Bat Quat V3 - On/Off: ");
  }
  else{
    digitalWrite(FanL_Out, LOW);
    digitalWrite(FanN_Out, LOW);
    TimeFanDisplayed = 0;
    ModeFan = 0;
    Serial.println("Tat Quat V3"); 
  }
}

// Fan 30phut
BLYNK_WRITE(V4){  
  StatusButtonBlynk = param.asInt();
  if(StatusButtonBlynk == HIGH && ModeFan == 0){
  TimeFanDelay = 1800000;
      ModeFan = 1;
    CurrentFanTime = millis();
    }
  }

// Charger Smartphone 3h
  BLYNK_WRITE(V0){  
  StatusButtonBlynk = param.asInt();
  if(StatusButtonBlynk == HIGH && ModeCharger == 0){
  TimeChargerDelay = 7200000;
      ModeCharger = 1;
    CurrentChargerTime = millis();
    Serial.print("Charger Smartphone 3h: ");
    }
  }

// Test Fan 10s
  // BLYNK_WRITE(V2){  
  // StatusButtonBlynk = param.asInt();
  // if(StatusButtonBlynk == HIGH && ModeFan == 0){
  // TimeFanDelay = 10000;
  // TimeFanDisplayed = 1;
  //   ModeFan = 1;
  //   CurrentFanTime = millis();
  //   }
  // }

   BLYNK_WRITE(V2){  
  StatusButtonBlynk = param.asInt();
  if(StatusButtonBlynk == HIGH){
    lcd.noDisplay();
    lcd.noBacklight();
    }
    else
    {
      lcd.display();
      lcd.backlight();
    }
  }



void loop() {
  Blynk.run();
  thoigian = millis();
  // put your main code here, to run repeatedly:
  Temperature_C = dht.readTemperature();
  Temperature_F = dht.readTemperature(true);
  Humidity = dht.readHumidity();

  // Kiểm tra cảm biến có hoạt động hay không
  if(isnan(Temperature_C) || isnan(Temperature_F) || isnan(Humidity))
  {
    Serial.println("Không có giá trị trả về từ cảm biến DHT");
    lcd.clear();
    lcd.println("NOT FOUND");
    delay(1000);
  }

  if(!Blynk.connected())
  {
    digitalWrite(FanL_Out, HIGH);
    digitalWrite(FanN_Out, HIGH);
    digitalWrite(ChargerL_Out, HIGH);
    digitalWrite(ChargerN_Out, HIGH);
  }

  if(thoigian - CurrentRead >= TimeRead)
  {
    if(ModeFan == 1)
    {
    if(thoigian - CurrentFanTime <= TimeFanDelay)
    {
          TimeFanDisplayed = (TimeFanDelay - (thoigian - CurrentFanTime))/60000;

      if(StartedFan ==0)
      {
        Serial.println("Bat Quat V4");  
      digitalWrite(FanL_Out, HIGH);
      digitalWrite(FanN_Out, HIGH);
      Serial.println("Da bat quat");
      StartedFan = 1;
      }
    }

    else{
      OffFan();
      Serial.println("Da Tat quat");
    }
  }

  if(ModeCharger == 1)
{
  if(thoigian - CurrentChargerTime <= TimeChargerDelay)
    {
          TimeChargerDisplayed = (TimeChargerDelay - (thoigian - CurrentChargerTime))/60000;

      if(StartedCharger ==0)
      {
        Serial.println("Bat dau sac");  
      digitalWrite(ChargerL_Out, HIGH);
      digitalWrite(ChargerN_Out, HIGH);
      StartedCharger = 1;
      }
    }

    else{
      OffCharger();
      Serial.println("Da Tat sac");
    }
}




    CurrentRead = millis();
  
    // Serial 
  Serial.print("Độ ẩm: ");
  Serial.print(Humidity);

  Serial.print(" - Nhiệt độ C: ");
  Serial.print(Temperature_C);

  Serial.print(" - Nhiệt độ F:: ");
  Serial.print(Temperature_F);


  // LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("H: ");
  lcd.setCursor(3, 0);
  lcd.print(Humidity);

  if(Count <= 2)
  {
    lcd.setCursor(9, 0);
    lcd.print("Fan: ");
    lcd.setCursor(14, 0);
    lcd.print(TimeFanDisplayed);

  Serial.print(" - TimeFanDisplayed: ");
  Serial.println(TimeFanDisplayed);
  }
  else if(Count >2 && Count <= 4)
  {
    lcd.setCursor(9, 0);
    lcd.print("Sac:");
    lcd.setCursor(13, 0);
    lcd.print(TimeChargerDisplayed);

  Serial.print(" - TimeChargerDisplayed: ");
  Serial.println(TimeChargerDisplayed);
  if(Count == 4)
  {
    Count = 0;
  }
  }

  lcd.setCursor(0, 1);
  lcd.print("C/F: ");
  lcd.setCursor(5, 1);
  lcd.print(Temperature_C);
  lcd.setCursor(10, 1);
  lcd.print("/");
  lcd.setCursor(11, 1);
  lcd.print(Temperature_F);
  Count = Count + 0.5;
  }


}
