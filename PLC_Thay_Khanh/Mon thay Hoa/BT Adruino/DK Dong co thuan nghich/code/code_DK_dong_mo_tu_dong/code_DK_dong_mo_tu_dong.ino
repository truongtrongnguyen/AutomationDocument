int mo=A13;
int dong=A14;
int dung=A15;
int ht_mo=A6;
int ht_dong=A5;
int cb_as=4;
int cb_mua=3;

int in1=15;
int in2=16;
int in3=17; 
int in4=18;
int ena=14;
int enb=19;
int led_mo=A2;
int led_dong=A3;
int led_dung=A4;
int led=13;
int khoa=0;
int chay=1;

boolean tt_mo=LOW;
boolean tt_dong=LOW;
boolean tt_dung=LOW;
boolean tt_ht_mo=LOW;
boolean tt_ht_dong=LOW;
boolean tt_cb_as=LOW;
boolean tt_cb_mua=LOW;

boolean dk_mo=LOW;
boolean dk_dong=LOW;
boolean dk_dung_mo=LOW;
boolean dk_dung_dong=LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(mo, INPUT);
pinMode(dong, INPUT);
pinMode(dung, INPUT);
pinMode(ht_mo, INPUT);
pinMode(ht_dong, INPUT);
pinMode(cb_as, INPUT);
pinMode(cb_mua, INPUT);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(ena, OUTPUT);
pinMode(enb, OUTPUT);

pinMode(led_mo, OUTPUT);
pinMode(led_dong, OUTPUT);
pinMode(led_dung, OUTPUT);
pinMode(led, OUTPUT);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
digitalWrite(ena, LOW);
digitalWrite(enb, LOW);

digitalWrite(led_mo, LOW);
digitalWrite(led_dong, LOW);
digitalWrite(led_dung, HIGH);
digitalWrite(led, LOW);
delay(10);
}
void loop() {
  // put your main code here, to run repeatedly:

tt_dung=!digitalRead(dung);
tt_mo=!digitalRead(mo);
tt_dong=!digitalRead(dong);

tt_ht_mo=digitalRead(ht_mo);
tt_ht_dong=digitalRead(ht_dong);
tt_cb_as=!(digitalRead(cb_as));   //trời sáng cho đổi lên 1
tt_cb_mua=!(digitalRead(cb_mua)); //trời mưa cho đổi lên 1
dk_chay();
delay(10);
}

void dk_chay()
{
dk_mo=((tt_mo==HIGH) || (tt_cb_as==HIGH && tt_cb_mua==LOW) && (tt_ht_mo==LOW) && (tt_dung==LOW));
dk_dong=((tt_dong==HIGH) or tt_cb_mua==HIGH && (tt_ht_dong== LOW) && (tt_dung==LOW));

dk_dung_mo=(tt_ht_mo==HIGH && khoa==1 || tt_dung==HIGH);
dk_dung_dong=(tt_ht_dong==HIGH && khoa==2 || tt_dung==HIGH);

if(dk_mo==HIGH) { mo_man(); }
if(dk_dong==HIGH) { dong_man(); }
if(dk_dung_mo==HIGH) { dung_mo(); }
if(dk_dung_dong==HIGH) {dung_dong(); }
delay(10);
}

void mo_man()
{
//if((tt_mo==HIGH && tt_ht_mo==LOW) || (tt_cb_as==HIGH && tt_cb_mua==LOW))
  digitalWrite(led_dung, LOW);
  digitalWrite(led_mo, HIGH);
  digitalWrite(led_dong, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(ena, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enb, LOW);
  khoa=1;
  delay(100);
}
void dong_man()
{
  //if((tt_dong==HIGH && tt_ht_dong==LOW) or (tt_cb_mua==HIGH))
  chay=0;
  digitalWrite(led_dung, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ena, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enb, HIGH);
  khoa=2;
  delay(100);
}

void dung_mo()
{
  //if(tt_ht_mo==HIGH && khoa==1 || tt_dung==HIGH)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ena, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, LOW);
  digitalWrite(led_dung, HIGH);
  delay(100);
}
void dung_dong()
{
  //if(tt_ht_dong==HIGH && khoa==2 || tt_dung==HIGH)
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enb, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, LOW);
  digitalWrite(led_dung, HIGH);
  delay(100);
}
void dung_mac_dinh()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ena, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enb, LOW);
  digitalWrite(led_mo, LOW);
  digitalWrite(led_dong, LOW);
  digitalWrite(led_dung, HIGH);
  delay(100);
}

