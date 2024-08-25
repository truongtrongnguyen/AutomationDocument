#include <DateTime.h>
#include <DateTimeStrings.h>
int nutnhan = 7;
int phaA = 8;
int phaB = 9;



bool tt_nutnhan = LOW;

int hientai, bandau, dem = 0;

int Power2 = 11;
int GND1 = 10;
int Sensor = 12;
bool tt_Sensor;

void setup() {
  // put your setup code here, to run once:
  pinMode(nutnhan, INPUT);
  pinMode(phaA, INPUT);
  pinMode(phaB, INPUT);

  pinMode(Power2, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(Sensor, INPUT);
  
  digitalWrite(Power2, HIGH);
  digitalWrite(GND1, LOW);

  Serial.begin(9600);

  bandau = digitalRead(phaA);

}

void loop() {
  // put your main code here, to run repeatedly:
  tt_nutnhan = digitalRead(nutnhan);
  // Serial.print("tt_nutnhan: ");
  // Serial.println(tt_nutnhan);

  hientai = digitalRead(phaA);
  if(hientai != bandau){  
    if(digitalRead(phaB) != hientai){
      dem++;
    }
    else {
      dem--;
    }
  Serial.print("Giatri: ");
  Serial.println(dem);
  }
  bandau = hientai;


  tt_Sensor = digitalRead(Sensor);
  Serial.print("tt_nutnhan: ");
  Serial.println(tt_Sensor);
}
