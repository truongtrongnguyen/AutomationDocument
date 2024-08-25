#include "OneButton.h" 

// https://github.com/mathertel/OneButton
                          
int nutnhan = 4; int gtnutnhan;

OneButton button(nutnhan, true);                       

int led = 1; int trangthai_led = LOW;
int dem1=0; int dem2=0; int dem3=0;
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(led, OUTPUT);                                                   
    
  button.attachDoubleClick(nhan_double);  //Kích hoạt lệnh khi nhấn liên tục 2 lần       
  button.attachClick(nhan_don);   //Kích hoạt lệnh khi nhấn 1 lần rồi nhả               
  button.attachLongPressStart(nhan_giu); //Kích hoạt lệnh khi nhấn giữ 1s
  //attachDuringLongPress Kích hoạt lệnh liên tục miễn là còn nhấn nút
  //attachLongPressStop Kích hoạt lệnh khi nút nhận được nhả ra
  //attachMultiClick Thực hiện lệnh sau khi nhiều lần nhấn

  digitalWrite(led, trangthai_led);
} 
  
void loop() 
{ 
  gtnutnhan = digitalRead(nutnhan);
  //Serial.print("Nút nhấn: "); Serial.println(gtnutnhan);  
  button.tick(); //Kiểm tra trạng thái nút nhấn 
  delay(10);                                        
} 
 
void nhan_don() 
{  
 dem1 += 1;    
 Serial.print("Đếm 1: "); Serial.println(dem1);  
     
 trangthai_led = !trangthai_led;             
 digitalWrite(led,trangthai_led);                                                                                                
} 
 
void nhan_double()
{                                    
  dem2 += 1;     
  Serial.print("Đếm 2: "); Serial.println(dem2); 
  
  for(int i=0; i<=10; i++)
  {
    digitalWrite(led,HIGH); 
    delay(500);
    digitalWrite(led,LOW); 
    delay(50);   
  }
}
 
void nhan_giu()
{                                   
  dem3 += 1;             
  Serial.print("Đếm 3: "); Serial.println(dem3);  
  
  for(int i=0; i<=255; i++)
  {
    analogWrite(led, i);
    delay(100);                                                   
  }
  digitalWrite(led,LOW);  
}
