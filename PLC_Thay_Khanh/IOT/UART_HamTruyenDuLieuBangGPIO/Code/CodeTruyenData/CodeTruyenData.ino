#define TX_PIN 4 // Khai báo chân TX là chân số 4

#define TX_OUTPUT DDRD |= (1<<DDD4) // pinMode(TX_OUTPUT, OUTPUT)
// Khi gọi TX_OUTPUT thì nó sẽ tiến hành lệnh DDRD |= (1<<DDD4)

// x=LOW=0, x=HIGH=1=TRUE
#define write_TX(x) PORTD = ((x)?(PORTD|= 1<<PD4):(PORTD&(~(1<<PD4))))
// Toán tử 3 ngôi: Đầu tiên nó sẽ kiểm tra xem (x) truyền vào là HIGH thì là true, còn LOW là false
// Tương tự DigitalWrite(...);

// Khai báo tốc độ BAUD
unsigned int UART_Cycle = 0;
 
  void setup() {
  // put your setup code here, to run once:
  delay(10);
  UART_Begin(9600); 
  delay(10);
}
unsigned char a = 'a';

void loop() {
  // put your main code here, to run repeatedly:
  UART_WriteByte(a);
  delay(1000);
  a++;
}

void UART_Begin(unsigned int baud)
{
  UART_Cycle = 1.0/baud * 1000 * 1000;
  // Tốc độ là 1/F, đơn vị là microGiay nên chuyển từ s->us
  write_TX(HIGH); // Set lên mức cao
  TX_OUTPUT;  // đặt là ngõ ra
} 

// LSB first, Np Parity, 1 Stopbit
// uint8_t = unsigned char
// VD byte_out=1010.0110 --> thì trọng số thấp nhất là 0-1-1-0... được gởi đi đầu tiên
// mỗi lần gởi nó sẽ delay theo Baud và dịch sang phải 1 bit
// 1010.0110 -> ShiftRight1bit(0): 0101.0011
void UART_WriteByte(uint8_t byte_out)
{
  // (1) Sennd Start bit
  write_TX(LOW);
  delayMicroseconds(UART_Cycle);

  // (2) Send 8 bit DATA. LSB first
  int b;
  for(int i = 0; i<8; i++)
  {
    b = byte_out & 0X01; // lấy ra bit cuối cùng sử dụng lệnh And: 1And1=1,0And1=0 
    write_TX(b);
    byte_out >>=1;
    delayMicroseconds(UART_Cycle);
  }

  // (3) Send Stop bit
  write_TX(HIGH);
  delayMicroseconds(UART_Cycle);

  // (4) Comeback to IDEAL state
  write_TX(HIGH);
}















