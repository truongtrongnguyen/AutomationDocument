int thuan=A13;
int nghich=A14;
int dung=A15;
int led_thuan=A2;
int led_nghich=A3;
int led_dung=A4;
boolean tt_thuan=LOW;
boolean tt_nghich=LOW;
boolean tt_dung=LOW;
int in1=15;
int in2=16;
int ena=14;


void setup() {
  // put your setup code here, to run once:
pinMode(thuan, INPUT);
pinMode(nghich, INPUT);
pinMode(dung, INPUT);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(ena, OUTPUT);


pinMode(led_thuan, OUTPUT);
pinMode(led_nghich, OUTPUT);
pinMode(led_dung, OUTPUT);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(ena, LOW);

digitalWrite(led_thuan, LOW);
digitalWrite(led_nghich, LOW);
digitalWrite(led_dung, HIGH);
delay(10);
}
void loop() {
  // put your main code here, to run repeatedly:
tt_thuan=digitalRead(thuan);
tt_nghich=digitalRead(nghich);
tt_dung=digitalRead(dung);
}

/*if(tt_dung==HIGH)
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
}*/
