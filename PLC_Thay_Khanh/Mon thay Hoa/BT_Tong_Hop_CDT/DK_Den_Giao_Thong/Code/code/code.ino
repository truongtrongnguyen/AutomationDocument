int a[]={
  64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

int vr= A0;

int xung=13;
int dulieu=12;
int chot=11;

int xung1=7;
int dulieu1=6;
int chot1=5;

int Xanh=10;
int Do =9;
int Vang=8;

int Value=0;

void setup() {
  // put your setup code here, to run once:
pinMode(vr, INPUT);
  
pinMode(xung, OUTPUT);
pinMode(dulieu, OUTPUT);
pinMode(chot, OUTPUT);

pinMode(Xanh, OUTPUT);
pinMode(Do, OUTPUT);
pinMode(Vang, OUTPUT);

pinMode(xung1, OUTPUT);
pinMode(dulieu1, OUTPUT);
pinMode(chot1, OUTPUT);

digitalWrite(Xanh, LOW);
digitalWrite(Vang, LOW);
digitalWrite(Do, LOW);

      digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 127);
    digitalWrite(chot, HIGH);

          digitalWrite(chot1, LOW);
    shiftOut(dulieu1, xung1, MSBFIRST, 127);
    digitalWrite(chot1, HIGH);
    delay(1);
}

void loop() { 
  // put your main code here, to run repeatedly:
Value = analogRead(vr);

if((Value>=426 && Value<512)||(Value>=639 && Value<720)){
  // Gio cao diem: 10h-12h  --> 1024/24* so gio
    Den_Xanh_Gio_Cao_Diem();
    Den_Vang();
    Den_Do_Gio_Cao_Diem();
}
else if(Value>=0&& Value<170){

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 127);
    digitalWrite(chot, HIGH);

          digitalWrite(chot1, LOW);
    shiftOut(dulieu1, xung1, MSBFIRST, 127);
    digitalWrite(chot1, HIGH);
    delay(1);

    
  digitalWrite(Xanh, LOW);
  digitalWrite(Vang, HIGH);
  digitalWrite(Do, LOW);
  delay(300);
  digitalWrite(Vang, LOW);
  delay(300);
}
else{
  Den_Xanh();
  Den_Vang();
  Den_Do();
  }
}


void Den_Xanh(){
  digitalWrite(Xanh, HIGH);
  digitalWrite(Vang, LOW);
  digitalWrite(Do, LOW);
  for(int j=2;j>=0;j--){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, a[j]);
    digitalWrite(chot, HIGH);
    for(int i=9;i>=0;i--)
    {
      digitalWrite(chot1, LOW);
      shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
      digitalWrite(chot1, HIGH);
      delay(300);
      }
   }
}


void Den_Vang(){
  digitalWrite(Xanh, LOW);
  digitalWrite(Vang, HIGH);
  digitalWrite(Do, LOW);
  
   digitalWrite(chot1, LOW);
   shiftOut(dulieu1, xung1, MSBFIRST, 127);
   digitalWrite(chot1, HIGH);
  
    for(int i=4;i>=0;i--){
    digitalWrite(chot1, LOW);
    shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
    digitalWrite(chot1, HIGH);
    delay(300);}
}


void Den_Do(){
  digitalWrite(Xanh, LOW);
  digitalWrite(Vang, LOW);
  digitalWrite(Do, HIGH);

  for(int j=3;j>=0;j--){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, a[j]);
    digitalWrite(chot, HIGH);

    if(j==3){
       for(int i=4;i>=0;i--){
       digitalWrite(chot1, LOW);
       shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
       digitalWrite(chot1, HIGH);
       delay(300);
     }
    }

    if(j<3){
      for(int i=9;i>=0;i--){
      digitalWrite(chot1, LOW);
      shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
      digitalWrite(chot1, HIGH);
      delay(300);
      }
    }
  }
}


void Den_Xanh_Gio_Cao_Diem(){
  digitalWrite(Xanh, HIGH);
  digitalWrite(Vang, LOW);
  digitalWrite(Do, LOW);
  
  for(int j=4;j>=0;j--){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, a[j]);
    digitalWrite(chot, HIGH);
    
    if(j==4){
      for(int i=4;i>=0;i--){
      digitalWrite(chot1, LOW);
      shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
      digitalWrite(chot1, HIGH);
      delay(300);
      }
    }

    if(j<4){
      for(int i=9;i>=0;i--){
      digitalWrite(chot1, LOW);
      shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
      digitalWrite(chot1, HIGH);
      delay(300);
      }
    }
  }
}

void Den_Do_Gio_Cao_Diem(){
  digitalWrite(Xanh, LOW);
  digitalWrite(Vang, LOW);
  digitalWrite(Do, HIGH);

  
  for(int j=1;j>=0;j--){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, a[j]);
    digitalWrite(chot, HIGH);
    
    for(int i=9;i>=0;i--){
    digitalWrite(chot1, LOW);
    shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
    digitalWrite(chot1, HIGH);
    delay(300);
    }
  }
}
