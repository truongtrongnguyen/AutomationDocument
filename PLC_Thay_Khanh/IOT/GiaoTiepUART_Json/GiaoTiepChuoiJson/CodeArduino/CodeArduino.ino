// Khai báo thư viện cần thiết
#include <ArduinoJson.h>

// Khai báo thư viện SoftwareSerial
#include <SoftwareSerial.h>

#define RX_PIN 11 // Chân RX của cổng nối tiếp mềm
#define TX_PIN 12 // Chân TX của cổng nối tiếp mềm
#define LED_PIN 10

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Tạo một đối tượng cổng nối tiếp mềm

// Tạo một đối tượng JsonDocument có dung lượng 100 byte
StaticJsonDocument<100> doc;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  // Khởi tạo giao tiếp nối tiếp với tốc độ baud là 9600
  Serial.begin(9600);
  // Khởi tạo cổng nối tiếp ảo
  mySerial.begin(9600);
}

void loop() {
  // Kiểm tra xem có dữ liệu nào sẵn sàng trên cổng nối tiếp ảo hay không
  if (mySerial.available()) {
    // Đọc một dòng từ cổng nối tiếp ảo
    String line = mySerial.readStringUntil('\n');


    // Chuyển đổi chuỗi JSON thành đối tượng JsonDocument
    DeserializationError error = deserializeJson(doc, line);

    // Kiểm tra xem có lỗi nào trong quá trình chuyển đổi hay không
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    }

    // Lấy giá trị nhiệt độ và độ ẩm từ đối tượng JsonDocument
    float temperature = doc["temperature"];
    float humidity = doc["humidity"];
    int c = doc["Led"];

    // In các giá trị ra màn hình nối tiếp
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

     if (c == 48) { // Nếu ký tự là '0'
      // Bật led
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED is on"); // In trạng thái led qua cổng nối tiếp cứng
    }
    else if (c == 49) { // Nếu ký tự là 'f'
      // Tắt led
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED is off"); // In trạng thái led qua cổng nối tiếp cứng
    }
    else { // Nếu ký tự khác
      // Không làm gì
      Serial.println("Invalid command"); // In báo lỗi qua cổng nối tiếp cứng
    }
  }
}
