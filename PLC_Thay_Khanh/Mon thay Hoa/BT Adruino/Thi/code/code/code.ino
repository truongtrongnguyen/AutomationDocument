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
int khoa=0;

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

