int ht1=A0;
int ht2=A1;
int ht3=A2;
int cb1=A3;
int cb2=A4;

boolean tt_ht1=LOW;
boolean tt_ht2=LOW;
boolean tt_ht3=LOW;
boolean tt_cb1=LOW;
boolean tt_cb2=LOW;

int out1=13;
int out2=12;
int out3=11;
int out4=10;
int out5=9;

void setup() {
  // put your setup code here, to run once:
pinMode(out1, OUTPUT);
pinMode(out2, OUTPUT);
pinMode(out3, OUTPUT);
pinMode(out4, OUTPUT);
pinMode(out5, OUTPUT);

pinMode(ht1, INPUT);
pinMode(ht2, INPUT);
pinMode(ht3, INPUT);
pinMode(cb1, INPUT);
pinMode(cb2, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
tt_ht1=digitalRead(ht1);
if(tt_ht1==HIGH)
{
  digitalWrite(out1, HIGH);
  delay(300);
  digitalWrite(out1, LOW);
  delay(300);
}
else
{
  digitalWrite(out1, LOW);
  delay(300);
}

tt_ht2=digitalRead(ht2);
digitalWrite(out2, tt_ht2);

tt_ht3=digitalRead(ht3);
digitalWrite(out3, tt_ht3);

tt_cb1=digitalRead(cb1);
digitalWrite(out4, !tt_cb1);

tt_cb2=digitalRead(cb2);
digitalWrite(out5, !tt_cb2);
delay(300);
}
