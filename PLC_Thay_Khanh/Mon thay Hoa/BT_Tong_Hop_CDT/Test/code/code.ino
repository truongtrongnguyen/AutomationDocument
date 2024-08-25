int nutnhan = A0;
int xung = 13;
int dulieu = 12;
int chot = 11;
boolean tt_nutnhan = LOW;
void setup() {
  // put your setup code here, to run once:
pinMode(nutnhan, INPUT);
pinMode(xung, OUTPUT);
pinMode(dulieu, OUTPUT);
pinMode(chot, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tt_nutnhan = digitalRead(nutnhan);
  if(tt_nutnhan)
  {
   digitalWrite(chot, LOW);
   shiftOut(dulieu, xung, MSBFIRST, 19);
   digitalWrite(chot, HIGH);
   delay(1000);
   
   digitalWrite(chot, LOW);
   shiftOut(dulieu, xung, MSBFIRST, 198);
   digitalWrite(chot, HIGH);
   delay(1000);
   
   digitalWrite(chot, LOW);
   shiftOut(dulieu, xung, MSBFIRST, 93);
   digitalWrite(chot, HIGH);
   delay(1000);

   digitalWrite(chot, LOW);
   shiftOut(dulieu, xung, MSBFIRST, 255);
   digitalWrite(chot, HIGH);
   delay(1000);
  }
}
