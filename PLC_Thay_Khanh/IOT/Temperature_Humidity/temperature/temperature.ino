// adafruit sensor library
// dht library

#include<DHT.h> // Thư viện Nhiệt độ độ ẩm
#include <Wire.h> // Gọi thư viện I2c để sử dụng các thư viện có sẵn
#include <LiquidCrystal_I2C.h> // Thư viện LCD I2C

LiquidCrystal_I2C lcd(0x27,16,2); //Khai báo địa chỉ I2C (0x27 or 0x3F) và LCD 16x02

const int DHTPin = 5; // Chân Out của cảm biến nối chân số 5;

const int DHTType = DHT11; // Khai báo kiểu cảm biến là loại DHT11
// const int DHTType = DHT21; // Khai báo kiểu cảm biến là loại DHT21
// const int DHTType = DHT22; // Khai báo kiểu cảm biến là loại DHT22

DHT dht(DHTPin, DHTType); // Khai báo thư viện chân cảm biến và kiểu cảm biến

float Temperature_C = 0;  // Nhiệt độ C
float Humidity = 0; // Độ ẩm
float Temperature_F = 0;  // Nhiệt độ F

int Power = 2;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

   pinMode(Power, OUTPUT);
   digitalWrite(Power, HIGH);

   lcd.init(); //Khởi tạo màn hình LCD
   lcd.backlight(); // Bật màn hình LCD

   dht.begin(); // Khởi động cảm biến
}

void loop() {
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
    return;
  }

  Serial.print("Độ ẩm: ");
  Serial.print(Humidity);

  Serial.print(" - Nhiệt độ C: ");
  Serial.print(Temperature_C);

  Serial.print(" - Nhiệt độ F:: ");
  Serial.println(Temperature_F);

  // LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DoAm: ");
  lcd.setCursor(6, 0);
  lcd.print(Humidity);

  lcd.setCursor(0, 1);
  lcd.print("C/F: ");
  lcd.setCursor(5, 1);
  lcd.print(Temperature_C);
  lcd.setCursor(10, 1);
  lcd.print("/");
  lcd.setCursor(11, 1);
  lcd.print(Temperature_F);

  delay(1000);

}
