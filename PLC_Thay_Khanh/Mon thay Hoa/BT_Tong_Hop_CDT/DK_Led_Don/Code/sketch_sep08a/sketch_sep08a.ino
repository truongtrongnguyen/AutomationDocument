int led1=13;
int led2=12;
int led3=11;
int led4=10;
int led5=9;
int led6=8;
int led7=7;
int led8=6;

int Nut1=A0;
int Nut2=A1;
int Nut3=A2;

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

pinMode(Nut1, INPUT);
pinMode(Nut2, INPUT);
pinMode(Nut3, INPUT);

digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
tt_nut1=digitalRead(Nut1);
tt_nut2=digitalRead(Nut2);
tt_nut3=digitalRead(Nut3);

if(tt_nut1==HIGH)
{
digitalWrite(led2, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led8, HIGH);
digitalWrite(led1, LOW);
digitalWrite(led3, LOW);
digitalWrite(led5, LOW);
digitalWrite(led7, LOW);
delay(500);
digitalWrite(led1, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led7, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led4, LOW);
digitalWrite(led6, LOW);
digitalWrite(led8, LOW);
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
digitalWrite(led1, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led7, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led4, LOW);
digitalWrite(led6, LOW);
digitalWrite(led8, LOW);
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
digitalWrite(led1, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led7, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led4, LOW);
digitalWrite(led6, LOW);
digitalWrite(led8, LOW);
delay(500);

digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
delay(500);
}

if(tt_nut2==HIGH)
{
digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(100);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(100);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(100);
digitalWrite(led4, LOW);
digitalWrite(led5, HIGH);
delay(100);
digitalWrite(led5, LOW);
digitalWrite(led6, HIGH);
delay(100);
digitalWrite(led6, LOW);
digitalWrite(led7, HIGH);
delay(100);
digitalWrite(led7, LOW);
digitalWrite(led8, HIGH);
delay(100);

digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(100);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(100);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(100);
digitalWrite(led4, LOW);
digitalWrite(led5, HIGH);
delay(100);
digitalWrite(led5, LOW);
digitalWrite(led6, HIGH);
delay(100);
digitalWrite(led6, LOW);
digitalWrite(led7, HIGH);
delay(100);


digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(100);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(100);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(100);
digitalWrite(led4, LOW);
digitalWrite(led5, HIGH);
delay(100);
digitalWrite(led5, LOW);
digitalWrite(led6, HIGH);
delay(100);


digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(100);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(100);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(100);
digitalWrite(led4, LOW);
digitalWrite(led5, HIGH);
delay(100);

digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(100);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(100);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(100);


digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(100);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(100);

digitalWrite(led1, HIGH);
delay(100);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(100);

digitalWrite(led1, HIGH);
delay(100);

digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
}

if(tt_nut3==HIGH)
{
  digitalWrite(led2, HIGH);
  delay(500);
    digitalWrite(led7, HIGH);
  delay(500);
    digitalWrite(led1, HIGH);
  delay(500);
    digitalWrite(led3, HIGH);
  delay(500);
    digitalWrite(led8, HIGH);
  delay(500);
    digitalWrite(led5, HIGH);
  delay(500);
    digitalWrite(led6, HIGH);
  delay(500);
    digitalWrite(led4, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
}
}
