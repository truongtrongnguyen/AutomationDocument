#include<TM1637Display.h>
#include<DHT.h>

const int DHTPin = 5; // Chân Out của cảm biến nối chân số 5;
const int DHTType = DHT11; // Khai báo kiểu cảm biến là loại DHT11

DHT dht(DHTPin, DHTType); // Khai báo thư viện chân cảm biến và kiểu cảm biến
float Temperature_C = 0;  // Nhiệt độ C
float Humidity = 0; // Độ ẩm
float Temperature_F = 0;  // Nhiệt độ F

int Power = 4;

// Model connect pins (Digital Pins)
#define CKL 2
#define DIO 3 

TM1637Display display(CKL, DIO);

int temperature = 32;
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

// Display timer
int hour = 12;
int minu = 15;
int timerDisplay = 12 * 100 + minu;  // 1215
void setup() {
  // put your setup code here, to run once:
  display.setBrightness(7); // Cài đặt độ sáng từ 0 -7
  display.clear();
  delay(1000);


  Serial.begin(9600);
   pinMode(Power, OUTPUT);
   digitalWrite(Power, HIGH);

   dht.begin(); // Khởi động cảm biến

}

void loop() {
  // put your main code here, to run repeatedly:

  // Display Temperature
  // display.showNumberDec(temperature, false, 2, 0);
  // display.setSegments(doC, 2, 2);

  // Display Timer
  // display.showNumberDec(timerDisplay, false, 4, 0);
ReadTeperature();

  //Dem(9999);
}

void ReadTeperature()
{
  Temperature_C = dht.readTemperature();
  Temperature_F = dht.readTemperature(true);
  Humidity = dht.readHumidity();

  display.showNumberDec(round(Temperature_C), false, 2, 0);
  display.setSegments(doC, 2, 2);
  Serial.println(Temperature_C);
  delay(2000);

  display.showNumberDec(round(Temperature_F), false, 2, 0);
  display.setSegments(doF, 2, 2);
  Serial.println(Temperature_F);
  delay(2000);

  display.showNumberDec(round(Humidity), false, 2, 0);
  display.setSegments(doA, 2, 2);
  Serial.println(Humidity);
  delay(2000);
}

void Dem(int NumStep)
{
  for(; NumStep > 0; NumStep--)  //Interrate NumStep
  {
    display.showNumberDec(NumStep); //Display the Variable value;
    delay(2000);  //A half second delay between steps.
  }
}
