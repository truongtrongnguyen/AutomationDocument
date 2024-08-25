/*
 * tên ic...dung lượng...địa chỉ
 * 
 * 24c01....128 bytes....0->127
 * 24c02....256 bytes....0->255
 * 24c04....512 bytes....0->511
 * 24c08....1024 bytes....0->1023
 * 24c016....2kb....0->2047
 * 24c32....4kb....0->4095
 * 24c64....8kb....0->8191
 * 24c128....16kb....0->16383
 * 24c256....32kb....0->32767
 * 24c512....65,5kb....0->65635
 * 
 */
 
/*
 * LƯU Ý:
 * - Các kiểu dữ liệu trên các Board Arduino khác nhau có thể không giống nhau
 * VD: unsigned int từ 0-65535 nhưng trên Board Arduino DUE là từ 0 - 4,294,967,295
 * - Ghi vào EEPROM là số nguyên dương
 * - Kiểm tra các byte có bị ghi đè lên các ô nhớ khác không
 * VD: unsigned int tốn 2 byte bộ nhớ ROM, b ghi ở ô nhớ 56 có nghĩa là
 * b được ghi vào ô 56, 57 (do b có kiểu unsigned int nên tốn 2 byte ô nhớ),
 * ví dụ ta ghi 1 biến mới là M 2 byte vào ô nhớ 57 tức là M sẽ ghi vào ô 57, 58
 * khi đó M đã nằm đè lê 1 ô nhớ của b.
 */


#include <Wire.h>
#include <Eeprom24Cxx.h>
static Eeprom24C eeprom(256,0x50); // 24c256 - dung lượng 32kb; tất cả IC AT có địa chỉ 0x50 

byte a = 185; //byte 0-255
unsigned int b = 63123; // unsigned int 0-65535
unsigned long c = 4100200300; // 0 - 4,294,967,295 (4 tỷ)

void setup() 
{
  Serial.begin(9600);

  Serial.println("Đọc số byte bộ nhớ các biến a, b, c");
  Serial.print("a: "); Serial.print(sizeof(a)); // sizeof() trả về số byte bộ nhớ của 1 biến nào đó
  Serial.print("   "); Serial.print("b: "); Serial.print(sizeof(b)); 
  Serial.print("   "); Serial.print("c: "); Serial.println(sizeof(c));
  Serial.println("   "); Serial.println("Đọc từ bộ nhớ EEPROM");

  eeprom.write_1_byte(30, a); //ghi vào 1 ô nhớ
  eeprom.write_2_byte(56, b); //ghi vào 2 ô nhớ
  eeprom.write_4_byte(1000, c);
//  eeprom.write_8_byte Lỗi
}

void loop() 
{
  Serial.print("a: "); Serial.print(eeprom.read_1_byte(30)); Serial.print("   ");
  Serial.print("b: "); Serial.print(eeprom.read_2_byte(56)); Serial.print("   ");
  Serial.print("c: "); Serial.println(eeprom.read_4_byte(1000)); 
}
