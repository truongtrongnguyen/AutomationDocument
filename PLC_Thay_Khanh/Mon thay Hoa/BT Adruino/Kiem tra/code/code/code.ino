int mo=A0;
int dong=A1;
int dung=A2;
int ht_mo=A3;
int ht_dong=A4;

int in1=13;
int in2=12;
int in3=11;
int in4=10;
int ena=9;
int enb=8;
int led_mo=7;
int led_dong=6;
int led_dung=5;
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

digitalWrite(led_dung, HIGH);

}
void loop() {
  // put your main code here, to run repeatedly:
tt_mo=digitalRead(mo);
tt_dong=digitalRead(dong);
tt_dung=digitalRead(dung);
tt_ht_mo=digitalRead(ht_mo);
tt_ht_dong=digitalRead(ht_dong);

if((tt_dung==HIGH) || ((tt_ht_mo == HIGH) and (chay==1)) || ((tt_ht_dong == HIGH) and (chay==2)))
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

  delay(300);
}
if(tt_mo==HIGH)
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
  delay(300);
}
if(tt_dong==HIGH)
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
  delay(300);
}
}
