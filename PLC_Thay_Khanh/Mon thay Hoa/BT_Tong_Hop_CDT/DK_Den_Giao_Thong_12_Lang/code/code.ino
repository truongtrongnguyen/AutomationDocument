int a[]={
  64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

int vr= A0;

int Xung_L1 =13;
int DL_L1 =12;
int Chot_L1 =11;

int Xung_L2 =10;
int DL_L2 =9;
int Chot_L2=8;

int Xung_L3 =7;
int DL_L3 =6;
int Chot_L3 =5;

int Xung_L4 =4;
int DL_L4 =3;
int Chot_L4 =2;


int Value=0;

void setup() {
  // put your setup code here, to run once:
pinMode(vr, INPUT);
  
pinMode(Xung_L1, OUTPUT);
pinMode(DL_L1, OUTPUT);
pinMode(Chot_L1, OUTPUT);

pinMode(Xung_L2, OUTPUT);
pinMode(DL_L2, OUTPUT);
pinMode(Chot_L2, OUTPUT);

pinMode(Xung_L3, OUTPUT);
pinMode(DL_L3, OUTPUT);
pinMode(Chot_L3, OUTPUT);

pinMode(Xung_L4, OUTPUT);
pinMode(DL_L4, OUTPUT);
pinMode(Chot_L4, OUTPUT);

}

void loop() { 
  // put your main code here, to run repeatedly:
    L1();
}

void  L1(){
    digitalWrite(Chot_L1, LOW);
    shiftOut(DL_L1, Xung_L1, MSBFIRST, 97);
    digitalWrite(Chot_L1, HIGH);

    digitalWrite(Chot_L2, LOW);
    shiftOut(DL_L2, Xung_L2, MSBFIRST, 100);
    digitalWrite(Chot_L2, HIGH);

    digitalWrite(Chot_L3, LOW);
    shiftOut(DL_L3, Xung_L3, MSBFIRST, 97);
    digitalWrite(Chot_L3, HIGH);

    digitalWrite(Chot_L4, LOW);
    shiftOut(DL_L4, Xung_L4, MSBFIRST, 100);
    digitalWrite(Chot_L4, HIGH);
    delay(5000);

     digitalWrite(Chot_L1, LOW);
    shiftOut(DL_L1, Xung_L1, MSBFIRST, 73);
    digitalWrite(Chot_L1, HIGH);

    digitalWrite(Chot_L3, LOW);
    shiftOut(DL_L3, Xung_L3, MSBFIRST, 73);
    digitalWrite(Chot_L3, HIGH);
    delay(25000);

    digitalWrite(Chot_L1, LOW);
    shiftOut(DL_L1, Xung_L1, MSBFIRST, 82);
    digitalWrite(Chot_L1, HIGH);

    digitalWrite(Chot_L3, LOW);
    shiftOut(DL_L3, Xung_L3, MSBFIRST, 82);
    digitalWrite(Chot_L3, HIGH);
    delay(5000);

    digitalWrite(Chot_L1, LOW);
    shiftOut(DL_L1, Xung_L1, MSBFIRST, 100);
    digitalWrite(Chot_L1, HIGH);
    
    digitalWrite(Chot_L2, LOW);
    shiftOut(DL_L2, Xung_L2, MSBFIRST, 97);
    digitalWrite(Chot_L2, HIGH);
    
    digitalWrite(Chot_L3, LOW);
    shiftOut(DL_L3, Xung_L3, MSBFIRST, 100);
    digitalWrite(Chot_L3, HIGH);
    

    digitalWrite(Chot_L4, LOW);
    shiftOut(DL_L4, Xung_L4, MSBFIRST, 97);
    digitalWrite(Chot_L4, HIGH);
    delay(5000);



    digitalWrite(Chot_L2, LOW);
    shiftOut(DL_L2, Xung_L2, MSBFIRST, 73);
    digitalWrite(Chot_L2, HIGH);

    digitalWrite(Chot_L4, LOW);
    shiftOut(DL_L4, Xung_L4, MSBFIRST, 73);
    digitalWrite(Chot_L4, HIGH);
    delay(25000);

    
    digitalWrite(Chot_L2, LOW);
    shiftOut(DL_L2, Xung_L2, MSBFIRST, 82);
    digitalWrite(Chot_L2, HIGH);

    digitalWrite(Chot_L4, LOW);
    shiftOut(DL_L4, Xung_L4, MSBFIRST, 82);
    digitalWrite(Chot_L4, HIGH);
    delay(5000);
}

