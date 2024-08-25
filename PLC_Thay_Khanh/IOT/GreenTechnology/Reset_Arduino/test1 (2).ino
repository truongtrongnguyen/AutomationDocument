int cambien = 7; //Chân cảm biến nối chân số 7 Arduino

int giatri;
int gtmacdinh = 1;
int dem;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); //LCD 16x02, địa chỉ I2C là 0X27

int reset = 6;
int gtreset;

void setup() 
{
  Serial.begin(9600);

  pinMode(reset, INPUT_PULLUP);

  pinMode(cambien, INPUT); 

  lcd.init(); //Khởi động LCD
  lcd.backlight(); //Bật đèn nền
  lcd.setCursor(2,0); //Cột 2, hàng 0
  lcd.print("DEM SO LUONG"); 
  lcd.setCursor(0,1); //Cột 0, hàng 1
  lcd.print("SO LUONG: "); 

}

void loop() 
{
  gtreset = digitalRead(reset);
  giatri = digitalRead(cambien); //Đọc giá trị digital từ cảm biến và gán vào biến giatri

  if(gtreset == 0)
  {
    lcd.clear(); //Xóa màn hình
    lcd.setCursor(2,0); //Cột 2, hàng 0
    lcd.print("RESET.......");
    delay (1000);
    
    resetBoard();
  }
  
  if (giatri != gtmacdinh) //gia trị đọc từ cảm biến khác giá trị mặc định
  {
    if (giatri == 0) //Nếu giá trị = 0
      {
        dem++; //Biến đếm cộng 1
      }
    gtmacdinh = giatri; //giá trị mặc định = giá trị
  }

  Serial.print("Giá trị cảm biến là: ");
  Serial.print(giatri);
  Serial.print("   ");
  Serial.print("Số đếm: ");
  Serial.print(dem);
  Serial.print("   ");
  Serial.print("Reset: ");
  Serial.println(gtreset);
  Serial.println("      ");
  lcd.setCursor(10,1); //Cột 10, hàng 1
  lcd.print(dem); 
  delay(200);

}

void resetBoard()
{
  asm volatile ("jmp 0"); //Nhảy về dòng đầu tiên của chương trình
}
