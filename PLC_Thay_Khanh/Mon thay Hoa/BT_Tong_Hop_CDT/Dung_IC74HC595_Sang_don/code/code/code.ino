int a[]={
        //
        1,   2,   4,   8,   16,  32,  64, 128, 
        129, 130, 132, 136, 144, 160, 192,
        193, 194, 196, 200, 208, 224,
        225, 226, 228, 232, 240,
        241, 242, 244, 248,
        249, 250, 252,
        253, 254,
        255
        };

int b[]={1,   2,   4,   8,   16,  32,  64, 128};
int xung=13;
int dulieu=12;
int chot=11;
int value=0;
void setup() {
  // put your setup code here, to run once:
pinMode(xung, OUTPUT);
pinMode(dulieu, OUTPUT);
pinMode(chot, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<36; i++){
    digitalWrite(chot, LOW);
    shiftOut(dulieu, xung, MSBFIRST, a[i]);
    digitalWrite(chot, HIGH);
    delay(200);
  }
}
