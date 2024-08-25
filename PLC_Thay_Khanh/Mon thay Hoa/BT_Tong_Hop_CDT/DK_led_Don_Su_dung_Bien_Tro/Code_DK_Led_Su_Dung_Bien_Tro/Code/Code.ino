int led1=13;
int led2=12;
int led3=11;
int led4=10;
int led5=9;
int led6=8;
int led7=7;
int led8=6;
int led_start=4;
int led_stop=5;

int nut1=A0;
int nut2=A1;
int nut3=A2;
int vr=A3;
int value=0;
boolean tt_nut1=LOW;
boolean tt_nut2=LOW;
boolean tt_nut3=LOW;

void setup() {
  // put your setup code here, to run once:

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
pinMode(led8,OUTPUT);

pinMode(led_start, OUTPUT);
pinMode(led_stop, OUTPUT);
pinMode(nut1, INPUT);
pinMode(nut2, INPUT);
pinMode(nut3, INPUT);
pinMode(vr, INPUT);

digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
digitalWrite(led_start, LOW);
digitalWrite(led_stop, LOW);
delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  tt_nut1=digitalRead(nut1);
    tt_nut2=digitalRead(nut2);
      tt_nut3=digitalRead(nut3);
      value=analogRead(vr);


if((tt_nut1==HIGH)and(value<512)){
  digitalWrite(led_start, HIGH);

digitalWrite(led2, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led8, HIGH);
digitalWrite(led1, LOW);
digitalWrite(led3, LOW);
digitalWrite(led5, LOW);
digitalWrite(led7, LOW);
delay(500);

digitalWrite(led2, LOW);
digitalWrite(led4, LOW);
digitalWrite(led6, LOW);
digitalWrite(led8, LOW);
digitalWrite(led1, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led7, HIGH);
delay(500);
digitalWrite(led2, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led8, HIGH);
digitalWrite(led1, LOW);
digitalWrite(led3, LOW);
digitalWrite(led5, LOW);
digitalWrite(led7, LOW);
delay(500);

digitalWrite(led2, LOW);
digitalWrite(led4, LOW);
digitalWrite(led6, LOW);
digitalWrite(led8, LOW);
digitalWrite(led1, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led7, HIGH);
delay(500);
digitalWrite(led2, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led8, HIGH);
digitalWrite(led1, LOW);
digitalWrite(led3, LOW);
digitalWrite(led5, LOW);
digitalWrite(led7, LOW);
delay(500);

digitalWrite(led2, LOW);
digitalWrite(led4, LOW);
digitalWrite(led6, LOW);
digitalWrite(led8, LOW);
digitalWrite(led1, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led7, HIGH);
delay(500);

digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
digitalWrite(led_start, LOW);
digitalWrite(led_stop, LOW);
delay(100);
}
if(tt_nut2==HIGH){
  if(value>=819.2){
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(300);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(300);
  digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH);
  delay(300);
  digitalWrite(led6, LOW);
  digitalWrite(led7, HIGH);
  delay(300);
  digitalWrite(led7, LOW);
  digitalWrite(led8, HIGH);
  delay(300);

  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(300);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(300);
  digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH);
  delay(300);
  digitalWrite(led6, LOW);
  digitalWrite(led7, HIGH);
  delay(300);

  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(300);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(300);
  digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH);
  delay(300);

 digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(300);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(300);

   digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(300);

   digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(300);

   digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(300);

   digitalWrite(led1, HIGH);
  delay(300);
}
else{
  digitalWrite(led_stop, HIGH);
  delay(2000);
}
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
digitalWrite(led_start, LOW);
digitalWrite(led_stop, LOW);
delay(100);
}

if(tt_nut3==HIGH){
  digitalWrite(led2, HIGH);
  digitalWrite(led_start, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led_start, LOW);
  delay(300);
  digitalWrite(led7, HIGH);
  digitalWrite(led_stop, HIGH);
  delay(300);
  digitalWrite(led7, LOW);
  digitalWrite(led_stop, LOW);
  delay(300);
  digitalWrite(led1, HIGH);
  digitalWrite(led_stop, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led_stop, LOW);
  delay(300);
  digitalWrite(led3, HIGH);
  digitalWrite(led_stop, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
  digitalWrite(led_stop, LOW);
  delay(300);
  digitalWrite(led8, HIGH);
  digitalWrite(led_start, HIGH);
  delay(300);
  digitalWrite(led8, LOW);
  digitalWrite(led_start, LOW);
  delay(300);
  digitalWrite(led5, HIGH);
  digitalWrite(led_stop, HIGH);
  delay(300);
  digitalWrite(led5, LOW);
  digitalWrite(led_stop, LOW);
  delay(300);
  digitalWrite(led6, HIGH);
  digitalWrite(led_start, HIGH);
  delay(300);
  digitalWrite(led6, LOW);
  digitalWrite(led_start, LOW);
  delay(300);
  digitalWrite(led4, HIGH);
  digitalWrite(led_start, HIGH);
  delay(300);
  digitalWrite(led4, LOW);
  digitalWrite(led_start, LOW);
  delay(300);
}
}
