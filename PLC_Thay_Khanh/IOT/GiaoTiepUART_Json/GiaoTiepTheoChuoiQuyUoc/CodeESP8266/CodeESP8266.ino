#include <DHTesp.h> // Thư viện cho cảm biến DHT11
#include <SoftwareSerial.h> // Thư viện cho EspSoftwareSerial

#define DHTPIN D0 // Chân kết nối với cảm biến
#define RX_PIN D1 // Chân RX của EspSoftwareSerial
#define TX_PIN D2 // Chân TX của EspSoftwareSerial

DHTesp dht; // Tạo một đối tượng DHT
SoftwareSerial mySerial(RX_PIN, TX_PIN); // Tạo một đối tượng EspSoftwareSerial

void setup() {
  Serial.begin(9600); // Khởi tạo cổng nối tiếp cứng với tốc độ baud là 9600
  mySerial.begin(9600); // Khởi tạo cổng nối tiếp mềm với tốc độ baud là 9600
  dht.setup(DHTPIN, DHTesp::DHT11); // Khởi tạo cảm biến
}

void loop() {
  delay(2000); // Đợi 2 giây

  TempAndHumidity th = dht.getTempAndHumidity(); // Đọc độ ẩm và nhiệt độ

  if (dht.getStatus() != DHTesp::ERROR_NONE) { // Kiểm tra xem có lỗi không
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //Thiết lập Data gửi đi dạng: "35.6;71.2" 2 giá trị phân cách bởi ';'
  String Data = String(th.temperature,1) + ";" + String(th.humidity,1);
  mySerial.println(Data); //Gửi giá trị nhiệt độ và độ ẩm qua Software serial
  Serial.println(Data); //In ra Serial Monitor chuỗi gửi đi
}
