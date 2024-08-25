#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 8, 7);

int Len = 4;
int Xuong =5 ;
int Ok = 6;
int pwm = 7;
int vr = A0;

class SinhVien {
  int Age;
  String Name;
}

bool tt_Len, tt_Xuong, tt_Ok;

int Led_Len = 1;
int Led_Xuong = 2;
int Led_Ok = 3;

int temp = 0;
int temp1 = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(15, 2);
  pinMode(Len, INPUT);
  pinMode(Xuong, INPUT);
  pinMode(Ok, INPUT);
  pinMode(vr, INPUT);

  pinMode(Led_Len, OUTPUT);
  pinMode(Led_Xuong, OUTPUT);
  pinMode(Led_Ok, OUTPUT);
  pinMode(pwm, OUTPUT);

  digitalWrite(Led_Len, LOW);
  digitalWrite(Led_Xuong, LOW);
  digitalWrite(Led_Ok, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Welcom To You");
  delay(500);
  lcd.setCursor(1, 1);
  lcd.print("Menu Home");

  attachInterrupt(0, Tatden, HIGH);
}

void Tatden(){
  digitalWrite(Led_Ok, HIGH);
}

void loop() {
 tt_Len = digitalRead(Len);
 tt_Xuong = digitalRead(Xuong);
 tt_Ok = digitalRead(Ok);
 delay(200);

if(tt_Len == HIGH && temp ==0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Den 1");
  lcd.setCursor(0, 1);
  lcd.print("Den 2");
  temp = 1;
   delay(100);
 }

 else if(tt_Len == HIGH && temp ==1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Den 1");
  lcd.setCursor(0, 1);
  lcd.print(">Den 2");
  temp = 2;
  delay(100);
 } 

 else if(tt_Len == HIGH && temp ==2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Den 3");
  temp = 0;
   delay(100);
 }


 else if(tt_Ok == HIGH && temp ==1 && temp1 == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Bat");
  lcd.setCursor(0, 1);
  lcd.print("Tat");
  temp1 = 1;
  temp = 3;
  delay(100);
 } 

  else if(tt_Len == HIGH && temp ==1 && temp1 ==0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Bat");
  lcd.setCursor(0, 1);
  lcd.print("Tat");
  temp1 = 0;
  temp = 1;
  delay(100);
 }

 else if(tt_Len == HIGH && temp ==3 && temp1 ==1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bat");
  lcd.setCursor(0, 1);
  lcd.print(">Tat");
  temp1 = 0;
  temp = 1;
  delay(100);
 } 

 


 else if(tt_Ok == HIGH && temp ==3 && temp1 ==1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcom To You");
  lcd.setCursor(1, 1);
  lcd.print("Menu Home");
  temp1 = 0;
  temp = 0;
  digitalWrite(Led_Len, HIGH);
  delay(100);
 } 

  else if(tt_Ok == HIGH && temp ==3 && temp1 ==2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcom To You");
  lcd.setCursor(1, 1);
  lcd.print("Menu Home");
  temp1 = 0;
  temp = 0;
  digitalWrite(Led_Len, LOW);
  delay(100);
 } 
 
}


