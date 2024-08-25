#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 8, 7);
// mảng sáng dồn
int a[]={
        
        1,   2,   4,   8,   16,  32,  64, 128, 
        129, 130, 132, 136, 144, 160, 192,
        193, 194, 196, 200, 208, 224,
        225, 226, 228, 232, 240,
        241, 242, 244, 248,
        249, 250, 252,
        253, 254,
        255
        };
//Mảng sáng dần
int b[]={1, 3, 7, 15, 31, 63, 127, 255};
// Mảng sáng led vị trí 6-4-2-0
int d[]={63, 15, 3, 0};

//Mảng đếm
int c[]={1, 2, 3, 4,5,6,7,8};
int e[]={6,4,2,0};

int xung=7;
int dulieu=6;
int chot=5;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(15, 2);
  pinMode(xung, OUTPUT);
  pinMode(dulieu, OUTPUT);
  pinMode(chot, OUTPUT);
  randomSeed(analogRead(0));

}

void loop() {
  // put your main code here, to run repeatedly:
//  ChopTat();
//  Sangdon();
  //Sang();
  lcd.setCursor(0, 0);
  lcd.print(random(300));
  delay(1000);
}

void ChopTat()
{
  lcd.setCursor(0,0);
  lcd.print("So luong: ");
  for(int i=0;i<3;i++)
  {
    lcd.setCursor(15, 2);
    lcd.print(8);
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 255);
    digitalWrite(chot, HIGH);
    delay(300);

    lcd.setCursor(15, 2);
    lcd.print(0);
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 0);
    digitalWrite(chot, HIGH);
    delay(300);  
  }
}
void Sangdon(){
    lcd.setCursor(0,0);
    lcd.print("So luong: ");
     for(int i=0;i<36; i++){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, a[i]);
    digitalWrite(chot, HIGH);
    lcd.setCursor(15, 2);
   if(i<8){
    lcd.setCursor(15, 2);
   lcd.print(1);
   }
   else if(i<14){
    lcd.setCursor(15, 2);
   lcd.print(2);
   }
   else if(i<21){
    lcd.setCursor(15, 2);
   lcd.print(3);
   }
   else if(i<26){
    lcd.setCursor(15, 2);
   lcd.print(4);
   }
   else if(i<30){
    lcd.setCursor(15, 2);
   lcd.print(5);
   }
   else if(i<33){
    lcd.setCursor(15, 2);
   lcd.print(6);
   }
   else if(i<36){
    lcd.setCursor(15, 2);
   lcd.print(7);
   }
    delay(200);
  }
}

void Sang()
{
    lcd.setCursor(0,0);
  lcd.print("So luong: ");

   for(int i=0;i<8; i++){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, b[i]);
    digitalWrite(chot, HIGH);
    lcd.setCursor(15, 2);
   lcd.print(c[i]);
    delay(200);
  }

     for(int i=0, j=8; i<=3; i++){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, d[i]);
    digitalWrite(chot, HIGH);
    lcd.setCursor(15, 2);
     lcd.print(e[i]);
    delay(200);
  }
}

