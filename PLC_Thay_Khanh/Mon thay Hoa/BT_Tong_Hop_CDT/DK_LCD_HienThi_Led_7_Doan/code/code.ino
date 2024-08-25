#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
// Mang dem tu 0 den 9
int a[]={
  // Muon cho thang nao tat thi cong no lai
  64, 121, 36, 48, 25, 18, 2, 120, 0, 16 };

// Mang dem hang chuc
int b[]={64,64,64,64,64,64,64,64,64,64, 
          121,121,121,121,121,121,121,121,121,121,
          36,36,36,36,36,36,36,36,36,36,
          48,48,48,48,48,48,48,48,48,48 };

// Mang dem tu 0 den 40
int c[]={ 64, 121, 36, 48, 25, 18, 2, 120, 0, 16,
         64, 121, 36, 48, 25, 18, 2, 120, 0, 16,
          64, 121, 36, 48, 25, 18, 2, 120, 0, 16,
           64, 121, 36, 48, 25, 18, 2, 120, 0, 16
  };
int xung=7;
int dulieu=6;
int chot=5;

int xung1=4;
int dulieu1=3;
int chot1=2;

int value=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(15, 2);
  pinMode(xung, OUTPUT);
  pinMode(dulieu, OUTPUT);
  pinMode(chot, OUTPUT);

  pinMode(xung1, OUTPUT);
  pinMode(dulieu1, OUTPUT);
  pinMode(chot1, OUTPUT);
    digitalWrite(chot, LOW);
      shiftOut(dulieu, xung, MSBFIRST, 36);
      digitalWrite(chot, HIGH);
   
}

void loop() {
  // put your main code here, to run repeatedly:
/* 1. An hien thi
      + lcd.noDisplay();
      + lcd.display();
   2. Hien thi con tro
      - Con tro full o
          + lcd.blink();
          + lcd.noBlink();
      - Con tro gach noi:
          + lcd.cursor();
          + lcd.noCursor();
      - Chay chu: 
          + lcd.scrollDisplay(Lef(); || Right();)

*/
//sss();
//lcd.clear();
//aaa();
//lcd.clear();

}
void aaa(){
  // LCD hien thi "MHAP NHAY" va led 7 doan hien thi so lan nhap nhay, len den 10 lan
  for(int i=1;i<=10;i++){
    if(i<10){
      digitalWrite(chot, LOW);
      shiftOut(dulieu, xung, MSBFIRST, a[0]);
      digitalWrite(chot, HIGH);
   
      digitalWrite(chot1, LOW);
      shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
      digitalWrite(chot1, HIGH);
    }

   if(i==10){
      digitalWrite(chot, LOW);
      shiftOut(dulieu, xung, MSBFIRST, a[1]);
      digitalWrite(chot, HIGH);
   
      digitalWrite(chot1, LOW);
      shiftOut(dulieu1, xung1, MSBFIRST, a[0]);
      digitalWrite(chot1, HIGH);
   }
       lcd.setCursor(3,0);
       lcd.print("NHAP NHAY");
       lcd.display();
       delay(400);
       lcd.noDisplay();
       delay(400);  
  }
}

void sss(){
// LCD hien thi "DAO DONG" va dich chuyen qua lai theo nhip dem cua 2 led 7 doan
// Dem len tu 0 -> 33, Chu ban dau nam giua dong tren cua LCD
  
  lcd.setCursor(3,0);
  lcd.print("DAO DONG");
  lcd.display();
  for(int i=0;i<=33; i++){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, b[i]);
    digitalWrite(chot, HIGH);
   
    digitalWrite(chot1, LOW);
    shiftOut(dulieu1, xung1, MSBFIRST, c[i]);
    digitalWrite(chot1, HIGH);
    
    if(i<=4){
      lcd.scrollDisplayRight();
    }
     else if(i<=12){
      lcd.scrollDisplayLeft();
     }
      else if(i<=20){
      lcd.scrollDisplayRight();
     }
      else if(i<=28){
      lcd.scrollDisplayLeft();
     }
      else if(i<=33){
      lcd.scrollDisplayRight();
     }
    delay(400);
  }
}
