
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
 * 
 * LƯU Ý: Trong ISR không dùng được delay hoặc millis. Hàm ngắt phải ngắn nhất có thể,
 * nếu delay bên trong một ISR sẽ gây ra gián đoạn trong ISR đó và các ngắt khác (mức ưu tiên thấp hơn) 
 * sẽ không được thực thi nữa cho đến khi hết thời gian delay.
 * 
 */

int den = 7;
int nutnhan = 2; int gtnutnhan;

int dem = 0;

void thuchien_dem()
{
  Serial.println("Thực hiện ngắt");
  dem++;
}

void setup() 
{
  Serial.begin(9600);
  
  pinMode(den, OUTPUT);
  pinMode(nutnhan, INPUT_PULLUP);
  attachInterrupt(0, thuchien_dem, FALLING);
}

void loop() 
{
  gtnutnhan = digitalRead(nutnhan);
  Serial.print("Nút nhấn: "); Serial.print(gtnutnhan);
  Serial.print("    "); Serial.print("Đếm: "); Serial.println(dem);
  
  digitalWrite(den, HIGH);
  delay(1000);
  digitalWrite(den, LOW);
  delay(500);
}
