#include<TM1637Display.h>
#include<DHT.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); ;

const int DHTPin = 5; // Chân Out của cảm biến nối chân số 5;
const int DHTType = DHT11; // Khai báo kiểu cảm biến là loại DHT11

DHT dht(DHTPin, DHTType); // Khai báo thư viện chân cảm biến và kiểu cảm biến
float Temperature_C = 0;  // Nhiệt độ C
float Humidity = 0; // Độ ẩm
float Temperature_F = 0;  // Nhiệt độ F

int Power = 4;
int Power1 = 6;

int Power2 = 9;
int GND1 = 7;
int Sensor = 8;

// Model connect pins (Digital Pins)
#define CKL 2
#define DIO 3 

TM1637Display display(CKL, DIO);

const uint8_t doC[] = {
	SEG_A | SEG_B | SEG_G | SEG_F,   // o
	SEG_A | SEG_D | SEG_E | SEG_F,   // C
	};

const uint8_t doF[] = {
	SEG_A | SEG_B | SEG_G | SEG_F,   // o
	SEG_A | SEG_E | SEG_F | SEG_G,   // F
	};

const uint8_t doA[] = {
	SEG_A | SEG_B | SEG_G | SEG_F,   // o
	SEG_A | SEG_B | SEG_C | SEG_E| SEG_F| SEG_G  // A
	};

int timeLed = 10000;
int timeLcd = 1000;
unsigned long hientaiLed = 0;
unsigned long hientaiLcd = 0;
unsigned long thoigian;


void setup() {
  // put your setup code here, to run once:
  display.setBrightness(7); // Cài đặt độ sáng từ 0 -7
  display.clear();
  delay(1000);


  Serial.begin(9600);
   pinMode(Power, OUTPUT);
   digitalWrite(Power, HIGH);
   pinMode(Power1, OUTPUT);
   digitalWrite(Power1, HIGH);

   dht.begin(); // Khởi động cảm biến

   lcd.init();
   lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  Temperature_C = dht.readTemperature();
  Temperature_F = dht.readTemperature(true);
  Humidity = dht.readHumidity();
  thoigian = millis();


ReadTeperature();
}

void ReadTeperature()
{

  ShowLCD();
  display.showNumberDec(round(Temperature_C), false, 2, 0);
  display.setSegments(doC, 2, 2);
  Serial.println(Temperature_C);
  delay(2000);
  
  ShowLCD();
  display.showNumberDec(round(Temperature_F), false, 2, 0);
  display.setSegments(doF, 2, 2);
  Serial.println(Temperature_F);
  delay(2000);

  ShowLCD();
  display.showNumberDec(round(Humidity), false, 2, 0);
  display.setSegments(doA, 2, 2);
  Serial.println(Humidity);
  delay(2000);
}

void ShowLCD()
{
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
}
