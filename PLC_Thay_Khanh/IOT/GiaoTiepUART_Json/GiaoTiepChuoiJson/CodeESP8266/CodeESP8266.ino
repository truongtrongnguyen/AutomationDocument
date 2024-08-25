// Khai báo các thư viện cần thiết
#include <ArduinoJson.h>
#include <DHTesp.h>
#include <SoftwareSerial.h>
#include <typeinfo>

// Định nghĩa kiểu cảm biến DHT là DHT11 và số chân GPIO kết nối với cảm biến là 16
#define DHTTYPE DHTesp::DHT11
#define DHTPIN 16

// Tạo một đối tượng DHT để làm việc với cảm biến
DHTesp dht;

// Tạo một đối tượng JsonDocument có dung lượng 100 byte
StaticJsonDocument<150> doc;

#define RX_PIN D1 // Chân RX của EspSoftwareSerial
#define TX_PIN D2 // Chân TX của EspSoftwareSerial
// Tạo một đối tượng SoftwareSerial
SoftwareSerial mySerial(RX_PIN , TX_PIN ); // RX, TX

void setup() {
  // Khởi tạo giao tiếp nối tiếp với tốc độ baud là 9600
  Serial.begin(9600);
  // Khởi tạo cảm biến DHT
  dht.setup(DHTPIN, DHTTYPE);
  // Khởi tạo cổng nối tiếp ảo
  mySerial.begin(9600);
}

void loop() {
  // Đọc giá trị nhiệt độ và độ ẩm từ cảm biến
  float temperature = dht.getTemperature();
  float humidity = dht.getHumidity();

  if (Serial.available()) {
     int c = Serial.read();
     Serial.print("C: ");
     Serial.println(c);
     doc["Led"] = c;
  }

  // Nếu có dữ liệu từ cổng nối tiếp mềm, gửi nó sang cổng nối tiếp cứng
  if (mySerial.available()) {
    int c = mySerial.read();
     Serial.print("C: ");
     Serial.println(c);
     doc["Led"] = c;
  }


  // Kiểm tra xem các giá trị có hợp lệ hay không
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Gán giá trị nhiệt độ và độ ẩm vào đối tượng JsonDocument
  doc["temperature"] = temperature;
  doc["humidity"] = humidity;

  // Chuyển đổi đối tượng JsonDocument thành chuỗi JSON và gửi nó qua cổng nối tiếp ảo
  serializeJson(doc, mySerial);
  mySerial.println();

  // Chuyển đổi đối tượng JsonDocument thành chuỗi JSON và gửi nó qua cổng nối tiếp thật
  serializeJson(doc, Serial);
  Serial.println();

  // Đợi một giây
  delay(1000);
}
