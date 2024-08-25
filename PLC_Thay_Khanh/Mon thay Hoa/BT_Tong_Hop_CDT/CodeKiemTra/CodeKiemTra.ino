int xung =13;
int dulieu = 12;
int chot = 11;
int nut1 = A0;
int nut2 =A1;
boolean tt_nut1 = LOW;
boolean tt_nut2 = LOW;

int a[] = {1, 2, 4, 8, 16, 32, 64, 128};

void setup() {
  // put your setup code here, to run once:
pinMode(xung, OUTPUT);
pinMode(dulieu, OUTPUT);
pinMode(chot, OUTPUT);
pinMode(nut1, INPUT);
pinMode(nut2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tt_nut1 = digitalRead(nut1);
tt_nut2 = digitalRead(nut2);
if(tt_nut1 == HIGH){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 17);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 51);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 119);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 255);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 127);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 63);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 31);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 15);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 7);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 3);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 1);
    digitalWrite(chot, HIGH);
    delay(500);

    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 0);
    digitalWrite(chot, HIGH);
    delay(500);
}

if(tt_nut2==HIGH){
   digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 85);
    digitalWrite(chot, HIGH);
    delay(500);

     digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 170);
    digitalWrite(chot, HIGH);
    delay(500);

     digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 85);
    digitalWrite(chot, HIGH);
    delay(500);

     digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 170);
    digitalWrite(chot, HIGH);
    delay(500);

     digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 85);
    digitalWrite(chot, HIGH);
    delay(500);

     digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 170);
    digitalWrite(chot, HIGH);
    delay(500);

     digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, 0);
    digitalWrite(chot, HIGH);
    delay(500);
}
}
