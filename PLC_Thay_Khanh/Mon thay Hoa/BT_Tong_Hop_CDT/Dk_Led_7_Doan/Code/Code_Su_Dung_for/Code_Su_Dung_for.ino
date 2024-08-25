int a=6;
int b=5;
int c=4;
int d=3;
int e=2;
int f=1;
int g=0;

int a1=13;
int b1=12;
int c1=11;
int d1=10;
int e1=9;
int f1=8;
int g1=7;

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
pinMode(nut1, INPUT);
pinMode(nut2, INPUT);
pinMode(nut3, INPUT);
pinMode(vr, INPUT);
  
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
pinMode(a1, OUTPUT);
pinMode(b1, OUTPUT);
pinMode(c1, OUTPUT);
pinMode(d1, OUTPUT);
pinMode(e1, OUTPUT);
pinMode(f1, OUTPUT);
pinMode(g1, OUTPUT);

digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
digitalWrite(a1, HIGH);
digitalWrite(b1, HIGH);
digitalWrite(c1, HIGH);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, HIGH);
delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:

  tt_nut1=digitalRead(nut1);
  tt_nut2=digitalRead(nut2);
  tt_nut3=digitalRead(nut3);
  value=analogRead(vr);

  
if(tt_nut1==HIGH){
  for(int i=0;i<3;i++){
    so_0();
  }

  //Chay xong 6 lan cho tat het
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
}
   
if(tt_nut2==HIGH){
 
}


    // Nhấn nút Led chớp tắt 88 trong 5s
if(tt_nut3==HIGH){
  // Mỗi chương trình sáng 0.5s tắt 0.5s --> 1s
  while(true){
    Sang_tat_88_trong_5s(); 
  }
    

}



  /*
so_0();
so_10();
so_20();
so_30();
so_40();
so_50();
so_60();
so_70();
so_80();
so_90();*/
}

void Sang_tat_88_trong_5s(){
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);

digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, LOW);
digitalWrite(f1, LOW);
digitalWrite(g1, LOW);
delay(300);
  // Cho tắt hết
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);

digitalWrite(a1, HIGH);
digitalWrite(b1, HIGH);
digitalWrite(c1, HIGH);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, HIGH);
delay(300);
}


void Dem_14_len_31(){
    //So 1 hang chuc
digitalWrite(a1, HIGH);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, HIGH);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);

  so_20();

  // Bắt đầu từ số 30-31
   //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 3 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);

// Cho tat het
digitalWrite(a1, HIGH);
digitalWrite(b1, HIGH);
digitalWrite(c1, HIGH);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, HIGH);

digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
}

void so_0()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 0 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, LOW);
digitalWrite(f1, LOW);
digitalWrite(g1, HIGH);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_10()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 1 hang chuc
digitalWrite(a1, HIGH);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, HIGH);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}
void so_20()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 2 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, HIGH);
digitalWrite(d1, LOW);
digitalWrite(e1, LOW);
digitalWrite(f1, HIGH);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_30()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 3 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_40()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 4 hang chuc
digitalWrite(a1, HIGH);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, LOW);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_50()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 4 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, HIGH);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, HIGH);
digitalWrite(f1, LOW);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_60()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 6 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, HIGH);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, LOW);
digitalWrite(f1, LOW);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_70()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 7 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, HIGH);
digitalWrite(e1, HIGH);
digitalWrite(f1, HIGH);
digitalWrite(g1, HIGH);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_80()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 8 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, LOW);
digitalWrite(f1, LOW);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
}

void so_90()
{
    //So 0
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
    //So 9 hang chuc
digitalWrite(a1, LOW);
digitalWrite(b1, LOW);
digitalWrite(c1, LOW);
digitalWrite(d1, LOW);
digitalWrite(e1, HIGH);
digitalWrite(f1, LOW);
digitalWrite(g1, LOW);
delay(300);
//So 1
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 2
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 3
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(300);
//So 4
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 5
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 6
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 7
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
delay(300);
//So 8
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
//So 9
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(300);
} 
