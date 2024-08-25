int mode=A13;
int vr=A7;
int value=0;  //ĐỌC ÁP 0-5v <=> 0-1023
int dem=0;
int in1=11;
int in2=10;
int ena=9;

int led_dung=A2;
int led_thuan=A3;
int led_nghich=A4;

boolean tt_mode=LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(mode, INPUT);
pinMode(vr, INPUT);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(ena, OUTPUT);

pinMode(led_dung, OUTPUT);
pinMode(led_thuan, OUTPUT);
pinMode(led_nghich, OUTPUT);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(ena, LOW);
digitalWrite(led_dung, HIGH);
digitalWrite(led_thuan, LOW);
digitalWrite(led_nghich, LOW);

delay(10);
}
void loop() {
  // put your main code here, to run repeatedly:
tt_mode=digitalRead(mode);
if(tt_mode==HIGH)
{
  if(dem<3) 
    { 
     dem=dem+1;
     delay(1000);
    }
  else
    {
      dem=0; 
      delay(1000);
    }
}
if(dem==1)  //CHẠY THUẬN
{
  digitalWrite(led_dung, LOW);
  digitalWrite(led_thuan, HIGH);
  digitalWrite(led_nghich, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  value=analogRead(vr); //CHUYỂN TỪ 0-5v SANG 0-1023
  value=map(value, 0, 1023, 0, 255);
  analogWrite(ena, value);
  delay(500);
}
if(dem==3)
{
  digitalWrite(led_dung, LOW);
  digitalWrite(led_thuan, LOW);
  digitalWrite(led_nghich, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  value=analogRead(vr); //CHUYỂN TỪ 0-5v SANG 0-1023
  analogWrite(ena, value);
  delay(500);
}
if(dem==2||dem==0)
{
  digitalWrite(led_dung, HIGH);
  digitalWrite(led_thuan, LOW);
  digitalWrite(led_nghich, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(ena, 0);
  delay(500);
  }
}

