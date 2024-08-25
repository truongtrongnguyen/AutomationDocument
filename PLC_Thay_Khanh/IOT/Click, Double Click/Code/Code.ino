#include<OneButton.h>

int nutnhan = 4; 
int gtnutnhan;

OneButton button(nutnhan, true); // True là giá trị khởi động

int led = 1;
int tt_led = LOW;
int dem1 = 0;
int dem2 = 0;
int dem3 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);


  button.attachDoubleClick(nhan_double);  // Kích hoạt lệnh khi nhấn liên tục 2 lần
  button.attachClick(nhan_don);  // Kích hoạt lệnh khi nhấn 1 lần rồi nhả
  button.attachLongPressStart(nhan_giu); // Kích hoạt lệnh khi nhấn giữ 1 giây
//  button.attachDuringLongPress Kích hoạt lệnh liên tục miễn là còn nhấn nút
//  attachLongPressStop()   Kích hoạt lệnh khi nút nhấn được thả ra
//  attachMultiClick() Kích hoạt lệnh sau khi nhấn nhiều lần

digitalWrite(led, tt_led);

}

void loop() {
  // put your main code here, to run repeatedly:
  gtnutnhan = digitalRead(nutnhan);
  button.tick(); // Kiểm tra trạng thái nút nhấn
  delay(50);

}

void nhan_double(){
  dem2 += 1;
  Serial.print("Đếm 2: ");
  Serial.print(dem2);

  for(int i = 0; i< 10; i++)
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
}

void nhan_don(){
  dem1 += 1;
  Serial.print("Đếm 1: ");
  Serial.print(dem1);

  tt_led = !tt_led;
  digitalWrite(led, tt_led);
}

void nhan_giu(){
  dem3 += 1;
  Serial.print("Đếm 3: ");
  Serial.print(dem3);

  for(int i = 0; i<= 255; i++)
  {
    analogWrite(led, i);
    delay(100);  
  }
  digitalWrite(led, LOW);
}

