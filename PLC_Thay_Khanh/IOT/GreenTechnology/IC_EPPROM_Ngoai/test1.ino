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

#include <Wire.h>
#include <Eeprom24Cxx.h>
static Eeprom24C eeprom(256,0x50); // 24c256 - dung lượng 32kb; tất cả IC AT có địa chỉ 0x50 

byte a = 255; //byte từ 0-255
int diachi_ghi = 32700;
int giatri_doc;

void setup() 
{
  Serial.begin(9600);
  
  eeprom.write_1_byte(diachi_ghi, a); 
  delay(10);
}

void loop() 
{
  giatri_doc = eeprom.read_1_byte(diachi_ghi); 
  Serial.print("a = "); Serial.println(giatri_doc);
}
