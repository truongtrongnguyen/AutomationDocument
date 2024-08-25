int led = 5;

void setup() {
  // put your setup code here, to run once:
 pinMode(led, OUTPUT);
digitalWrite(led, HIGH);
  // Khởi tạo Serial để giao tiếp với máy tính và Serial Monitor 
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){
  // Nếu có dữ liệu từ Monitor gửi và hiển thị nó 
   char c = Serial.read();
   Serial.write(c);

   if(c == '0'){
     digitalWrite(led, HIGH);
     Serial.print(digitalRead( led));
   }
   if(c == '1'){
     digitalWrite(led, LOW);
     Serial.print(digitalRead( led));
   }
 }

//    digitalWrite(led, LOW);
//  delay(2000);
//  Serial.print(digitalRead( led));
//  digitalWrite(led, HIGH);
//  delay(500);
//  Serial.print(digitalRead( led));
}
