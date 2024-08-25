int mo=A13;
int dong=A14;
int dung=A15;
int ht_mo=A6;
int ht_dong=A5;

int in1=15;
int in2=16;
int in3=17;
int in4=18;
int ena=14;
int enb=19;
int led_mo=A2;
int led_dong=A3;
int led_dung=A4;
int chay=0;

boolean tt_mo=LOW;
boolean tt_dong=LOW;
boolean tt_dung=LOW;
boolean tt_ht_mo=LOW;
boolean tt_ht_dong=LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(mo, INPUT);
pinMode(dong, INPUT);
pinMode(dung, INPUT);
pinMode(ht_mo, INPUT);
pinMode(ht_dong, INPUT);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(ena, OUTPUT);
pinMode(enb, OUTPUT);

pinMode(led_mo, OUTPUT);
pinMode(led_dong, OUTPUT);
pinMode(led_dung, OUTPUT);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(ena, LOW);
digitalWrite(enb, LOW);

digitalWrite(led_mo, LOW);
digitalWrite(led_dong, LOW);
digitalWrite(led_dung, HIGH);
delay(10);
}
void loop() {
  // put your main code here, to run repeatedly:
tt_mo=!digitalRead(mo);
tt_dong=!digitalRead(dong);
tt_dung=!digitalRead(dung);
tt_ht_mo=digitalRead(ht_mo);
tt_ht_dong=digitalRead(ht_dong);

if(tt_dung==HIGH)
{
  digitalWrite(led_dung, HIGH);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);
  delay(100);
}
if(tt_mo==HIGH && tt_ht_mo==LOW)  //Khóa không cho chạy tiếp khi nó đang chạm công tắc hành trình
{
  digitalWrite(led_dung, LOW);
  digitalWrite(led_mo, HIGH);
  digitalWrite(led_dong, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(ena, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enb, LOW);
  chay=1;
  delay(100);
}
if(tt_dong==HIGH && tt_ht_dong==LOW)  //Khóa không cho chạy tiếp khi nó đang chạm công tắc hành trình
{
  digitalWrite(led_dung, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ena, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enb, HIGH);
  chay=2;
  delay(100);
}
if(tt_ht_mo==HIGH && chay==1)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ena, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, LOW);
  digitalWrite(led_dung, HIGH);
  delay(100);
}
if(tt_ht_dong==HIGH && chay==2)
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enb, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, LOW);
  digitalWrite(led_dung, HIGH);
  delay(100);
}
}
