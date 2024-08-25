
/*
 * Board.........0.....1.....2.....3.....4.....5
 * Uno, Ethernet 2.....3
 * Mega2560      2.....3.....21.....20....19....18
 * Leonardo      3.....2.....0.....1.....7
 * 
 * Cú pháp: attachInterrupt(interrupt, ISR, mode);
 * Các mode:
 * - LOW: thấp
 * - HIGH: cao
 * - RISING: thấp sang cao
 * - FALLING: cao sang thấp
 * - CHANGE: Khi có thay đổi từ LOW->HIGH hoặc HIGH->LOW thì nó sẽ gọi ISR
 * 
 * LƯU Ý: Trong ISR không dùng được delay hoặc millis. Hàm ngắt phải ngắn nhất có thể,
 * nếu delay bên trong một ISR sẽ gây ra gián đoạn trong ISR đó và các ngắt khác (mức ưu tiên thấp hơn) 
 * sẽ không được thực thi nữa cho đến khi hết thời gian delay.
 * 
 */

int enco = 2;
int dem = 0;
int rpm;

int timecho = 1000;
unsigned long thoigian;
unsigned long hientai;

void dem_xung()
{
  dem++; //đếm xung
}

void setup() 
{
  Serial.begin(9600);
  
  pinMode(enco, INPUT);
  attachInterrupt(0, dem_xung, RISING);
}

void loop() 
{
  thoigian = millis();
  Serial.print("Time: "); Serial.print(thoigian); Serial.print("   ");
  Serial.print("Hiện tại: "); Serial.println(hientai);
  
  if (thoigian - hientai >= timecho)
  {
    hientai = thoigian;
    rpm = (dem/20)*60; 
    Serial.print("\t\t\t\t"); Serial.print("Số xung/s: "); Serial.println(dem);
    dem = 0;   
    Serial.print("\t\t\t\t"); Serial.print("RPM: "); Serial.println(rpm);
  }
  
}
