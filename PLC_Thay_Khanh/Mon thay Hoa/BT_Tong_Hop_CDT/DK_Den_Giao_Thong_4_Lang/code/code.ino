int x1_3=13;
int v1_3=12;
int d1_3=11;
int x2=10;
int v2=9;
int d2=8;
int x4=7;
int v4=6;
int d4=5;
int giocaodiem = 3;
int giodemkhuya = 2;
int giobinhthuong = 1;
int Nut1=A0;
int value=0;

boolean tt_nut1=LOW;


void setup() {
  // put your setup code here, to run once:
pinMode(x1_3,OUTPUT);
pinMode(v1_3,OUTPUT);
pinMode(d1_3,OUTPUT);
pinMode(x2,OUTPUT);
pinMode(v2,OUTPUT);
pinMode(d2,OUTPUT);
pinMode(x4,OUTPUT);
pinMode(v4,OUTPUT);
pinMode(d4,OUTPUT);
pinMode(giocaodiem,OUTPUT);
pinMode(giodemkhuya,OUTPUT);
pinMode(giobinhthuong,OUTPUT);

pinMode(Nut1, INPUT);

digitalWrite(x1_3, LOW);
digitalWrite(v1_3, LOW);
digitalWrite(d1_3, LOW);
digitalWrite(x2, LOW);
digitalWrite(v2, LOW);
digitalWrite(d2, LOW);
digitalWrite(x4, LOW);
digitalWrite(v4, LOW);
digitalWrite(d4, LOW);
digitalWrite(giocaodiem, LOW);
digitalWrite(giodemkhuya, LOW);
digitalWrite(giobinhthuong, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Lay 1023 / 24h * so_gio
  value = analogRead(Nut1);
  if((value >= 430 && value<510)||(value>=610 && value<714)){
    digitalWrite(giocaodiem, HIGH);
    digitalWrite(giodemkhuya, LOW);
    digitalWrite(giobinhthuong, LOW);
    Gio_Cao_Diem(); // 67%
}
else if(value>=981 || value<170){
     digitalWrite(giocaodiem, LOW);
    digitalWrite(giodemkhuya, HIGH);
    digitalWrite(giobinhthuong, LOW);
    Gio_Dem_Khuya();  //99%
}
  else{
    digitalWrite(giocaodiem, LOW);
    digitalWrite(giodemkhuya, LOW);
    digitalWrite(giobinhthuong, HIGH);
    Gio_Binh_Thuong();
  }
}

void Gio_Binh_Thuong(){
  digitalWrite(x1_3, HIGH);
digitalWrite(v1_3, LOW);
digitalWrite(d1_3, LOW);
digitalWrite(x2, LOW);
digitalWrite(v2, LOW);
digitalWrite(d2, HIGH);
digitalWrite(x4, LOW);
digitalWrite(v4, LOW);
digitalWrite(d4, HIGH);
delay(30000);

digitalWrite(v1_3, HIGH);
digitalWrite(x1_3, LOW);
delay(5000);

digitalWrite(v1_3, LOW);
digitalWrite(d1_3, HIGH);
digitalWrite(d2, LOW);
digitalWrite(x2, HIGH);
delay(5000);

digitalWrite(d4, LOW);
digitalWrite(x4, HIGH);
delay(25000);

digitalWrite(x2, LOW);
digitalWrite(v2, HIGH);
digitalWrite(x4, LOW);
digitalWrite(v4, HIGH);
delay(5000);
}
void Gio_Cao_Diem(){
  digitalWrite(x1_3, HIGH);
  digitalWrite(v1_3, LOW);
  digitalWrite(d1_3, LOW);
  digitalWrite(x2, LOW);
  digitalWrite(v2, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(x4, LOW);
  digitalWrite(v4, LOW);
  digitalWrite(d4, HIGH);
  delay(40000);

  digitalWrite(v1_3, HIGH);
  digitalWrite(x1_3, LOW);
  delay(5000);

  digitalWrite(v1_3, LOW);
  digitalWrite(d1_3, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(x2, HIGH);
  delay(5000);

  digitalWrite(d4, LOW);
  digitalWrite(x4, HIGH);
  delay(15000);

  digitalWrite(x2, LOW);
  digitalWrite(v2, HIGH);
  digitalWrite(x4, LOW);
  digitalWrite(v4, HIGH);
  delay(5000);
}
void Gio_Dem_Khuya(){
  digitalWrite(x1_3, LOW);
  digitalWrite(v1_3, HIGH);
  digitalWrite(d1_3, LOW);
  digitalWrite(x2, LOW);
  digitalWrite(v2, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(x4, LOW);
  digitalWrite(v4, HIGH);
  digitalWrite(d4, LOW);
  delay(500);
  digitalWrite(v1_3, LOW);
  digitalWrite(v2, LOW);
  digitalWrite(v4, LOW);
  delay(500);
}

