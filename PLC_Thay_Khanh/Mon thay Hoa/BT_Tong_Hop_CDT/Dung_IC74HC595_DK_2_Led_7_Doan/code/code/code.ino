int a[]={
  64, 121, 36, 48, 25, 18, 2, 120, 0, 16
  
        };

int xung=13;
int dulieu=12;
int chot=11;

int xung1=7;
int dulieu1=6;
int chot1=5;
int value=0;
void setup() {
  // put your setup code here, to run once:
pinMode(xung, OUTPUT);
pinMode(dulieu, OUTPUT);
pinMode(chot, OUTPUT);

pinMode(xung1, OUTPUT);
pinMode(dulieu1, OUTPUT);
pinMode(chot1, OUTPUT);


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

digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, a[value]);
    digitalWrite(chot, HIGH);

    
for(int i=0;i<10;i++)
{
    digitalWrite(chot1, LOW);
    shiftOut(dulieu1, xung1, MSBFIRST, a[i]);
    digitalWrite(chot1, HIGH);
    delay(200);
}
value++;
if(value==10){
  value=0;
}
 
}
