/* Dự án sử dụng ESP8266 điều khiển biến tần bơm thông qua wifi bằng app Blynk IOT
 * Hiển thị các trạng thái hoạt động của hệ thống
 * Đồng bộ với LCD thực tế
 * Gửi thông báo các tình trạng về điện thoại
 * Tất cả các chân INPUT D1, D4, D5, D6, D7 được kích mức thấp (có sẵn  mức cao) 
 * Chân D0, D8 là 2 chân OUT, có sẵn mức thấp, hoạt động ở mức cao để kích hoạt
ESP 8266 có 9 chân I/O từ D0 tới D8
D0 xuất tín hiệu kích relay RUN biến tần
D1 nhận tín hiệu từ nút nhấn Start
D2 xuất tín hiệu I2C (SDA)
D3 xuất tín hiệu I2C (SCL)
D4 nhận tín hiệu từ nút nhấn Reset
D5 nhận tín hiệu Phao trên
D6 nhận tín hiệu Phao dưới
D7 nhận tín hiệu động cơ quá tải (relay OL của biến tần)
D8 xuất tín hiệu Reset toàn bộ hệ thống
A0 chân đọc giá trị biến trở (VR)
*/

// khai báo cơ bản-------------------------------------------------------------------------
#define BLYNK_PRINT Serial                                    // địa chỉ ID khi tạo Templates
#define BLYNK_TEMPLATE_ID "TMPLouuQzXVG"
#define BLYNK_DEVICE_NAME "ĐIỀU KHIỂN BƠM"
#define BLYNK_AUTH_TOKEN "fYt8vBIbaq1G2kY68gfgZU9JTiBDZd14"

#include <Wire.h>                     // thư viện kết nối bus I2C
#include <LiquidCrystal_I2C.h>        // thư viện I2C
LiquidCrystal_I2C lcd(0x27,16,2);     // khai báo loại lcd
#include <ESP8266WiFi.h>              // thư viện ESP8266
#include <BlynkSimpleEsp8266.h>       // thư viện kết nối ESP8266
char auth[] ="fYt8vBIbaq1G2kY68gfgZU9JTiBDZd14";
char ssid[]= "VIETTEL_PHUNG HOA";        // tên wifi         VIETTEL_PHUNG HOA       Phat         HamacoGreen
char pass[]= "99990000";          // pass wifi  99990000                12345678     HamacoGreen2021

// 2 nút đk trên webdashboard (Blynk IOT)---------------------------------------------------------------
int ON;          // V0      chân ảo ON trên webdashboard (Blynk IOT)
int OFF;         // V1      chân ảo OFF trên webdashboard (Blynk IOT)
int RST_app;     // V6      chân ảo RST trên webdashboard (Blynk IOT)

// khai  báo các chân ảo----------------------------------------------------------------------------------
WidgetLCD lcd_app (V2);          // chân ảo để đưa dữ liệu vào LCD ảo trên webdashboard (Blynk IOT)
WidgetLED bao_dc (V4);           // chân ảo để đưa dữ liệu vào LED báo động cơ trên webdashboard (Blynk IOT)
WidgetLED bao_nhiet (V5);        // chân ảo để đưa dữ liệu vào LED báo nhiệt trên webdashboard (Blynk IOT)
WidgetLED muc_nuoc_tren (V7);    // chân ảo để gửi dữ liệu mức nước trên lên webdashboard (Blynk IOT)

#define P_VR A0                  // chân analog đọc giá trị biến trở
#define P_START D1
#define P_RSTI D4                     
#define P_PHAOT D5
#define P_STOP_PD D6
#define P_TEMP D7  
#define P_ON D0       
#define P_RSTO D8      
#define P_SDA D2     
#define P_SCL D3

boolean tt_START=HIGH;      // trạng thái nút nhấn START
boolean tt_STOP_PD=HIGH;    // trạng thái nút nhấn STOP và PHAO mức dưới
boolean tt_PHAOT=HIGH;      // trạng thái PHAO mức trên
boolean tt_RSTI=HIGH;       //trạng thái nút nhấn RST
boolean tt_TEMP=HIGH;       // trạng thái relay OL của biến tần
int TOCDO=0;          // biến lưu cấp tốc độ
int ONL=0;            // biến lưu trạng thái chạy app Blynk IOT
int TAY=0;            // biến lưu trạng thái chạy bằng nút nhấn
int PHAO=0;           // biến lưu trạng thái chạy bằng phao
int VAL=0;            // biến lưu giá trị biến trở
int x=0;              // biến lưu trạng thái chạy: 0 chờ; 1 chạy; 2 dừng
int y=0;              // biến lưu trạng thái chạy phụ ; 0 chờ; 1 đang tắt; 2 dừng; 3 sau khi reset
int rst=0;            // biến lưu trạng thái reset

// đọc trạng thái nút ON V0 trên webdashboard (Blynk IOT)-----------------------------------------------------------
BLYNK_WRITE(V0){              // đọc trạng thái nút nhấn ON(V0) trên webdashboard (Blynk IOT)
  ON=param.asInt();
    delay(300);
  if((ON==1)and (TAY!=1) and (PHAO!=1)){                  // nếu có nhấn nút ON, không đang chạy ở 2 chế độ còn lại
    ONL=1;                                                 // vào trạng thái chạy onl
    TAY=0;                          
    PHAO=0;
    delay(20); 
                                          }
            }
// đọc trạng thái nút OFF V1 trên webdashboard (Blynk IOT)-------------------------------------------------------
BLYNK_WRITE(V1){                  // đọc trạng thái nút nhấn OFF trên webdashboard (Blynk IOT)
  OFF=param.asInt();
    delay(300);
  if(OFF==1){                     // nếu có nhấn OFF, vào trạng thái tắt   
    ONL=2;    
    TAY=2;    
    PHAO=2;
    delay(20);    
      }
    }
           
BLYNK_WRITE(V6){                  // đọc trạng thái nút nhấn RST V6 trên webdashboard (Blynk IOT)
  RST_app=param.asInt();
   delay(300);
  if(RST_app==1){                     // nếu có nhấn RST, tất cả về giá trị khởi tạo   
    ONL=0;                            // vào trạng thái rst, dừng chạy 
    TAY=0;    
    PHAO=0; 
    x=0;
    y=3;
    rst=1;
    delay(20);
      }
      }

void setup() {
// khai báo các chân OUT bình thường-----------------------------------------------------------------------------------
 pinMode(P_ON, OUTPUT);
 pinMode(P_RSTO, OUTPUT);
 pinMode(P_SDA, OUTPUT);
 pinMode(P_SCL, OUTPUT);
 
 //  khai báo các chân IN dạng PULLUP (có điện trở kéo lên sẵn mức cao, khi tác động thì đưa xuống mức 0)-----------------------
 pinMode(P_START, INPUT_PULLUP);
 pinMode(P_STOP_PD, INPUT_PULLUP);
 pinMode(P_PHAOT, INPUT_PULLUP);
 pinMode(P_TEMP, INPUT_PULLUP);
 pinMode(P_RSTI, INPUT_PULLUP);
 pinMode(P_VR, INPUT);
 
// xuất mức logic ban đầu---------------------------------------------------------------------------------------------------
 digitalWrite(P_ON,LOW);
 digitalWrite(P_RSTO,LOW);
 
// khởi chạy các đường truyền cần thiết--------------------------------------------------------------------------------------
 Wire.begin(D2,D3);       // 2 chân dữ liệu (SDA và SCL) điều khiển I2C
 Serial.begin(9600);      // khởi chạy cổng truyền nối tiếp với máy tính
 Blynk.begin(auth, ssid, pass);     // khởi tạo Blynk
//----------------------------------------------------------------------------------------------------------------------
        // khởi chạy, làm sạch, bật đèn nền cho LCD
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd_app.clear();      // làm  sạch LCD ảo trên webdashboard (Blynk IOT)
                        // các dòng giới thiệu cơ bản hiển thị trên lcd  
  lcd.setCursor(0,0);
  lcd.print("  TU BIEN TAN   ");
  lcd.setCursor(0,1);
  lcd.print(" EDS1000 3.7KW  ");
                                        //các dòng giới thiệu cơ bản hiển thị trên lcd ảo trên webdashboard (Blynk IOT)
  lcd_app.print(0,0,"  TU BIEN TAN  ");
  lcd_app.print(0,1," EDS1000 3.7KW  ");
  delay(1000);
  lcd.clear();
  lcd_app.clear();  
                                   // các dòng giới thiệu cơ bản hiển thị trên lcd  
  lcd.setCursor(0,0);
  lcd.print(" DIEU KHIEN BOM ");
  lcd.setCursor(0,1);
  lcd.print("3 PHA 2.2KW 3HP ");
                                         //các dòng giới thiệu cơ bản hiển thị trên lcd ảo trên webdashboard (Blynk IOT)
  lcd_app.print(0,0," DIEU KHIEN BOM ");
  lcd_app.print(0,1,"3 PHA 2.2KW 3HP ");
  delay(1000);
  lcd.clear();
  lcd_app.clear(); 
                                         
  lcd.setCursor(0,0);
  lcd.print("CO DIEN TU M.HOA");
  lcd.setCursor(0,1);
  lcd.print("   0397699040   ");

  lcd_app.print(0,0,"CO DIEN TU M.HOA");
  lcd_app.print(0,1,"   0397699040   ");
}
//---------------------------------------------------------------------------------------
void loop() {
 Blynk.run();                                              // chạy chương trình BLYNK                                                        // đọc trạng thái các input
  tt_START= digitalRead(P_START);               // đọc trạng thái nút nhấn Start
  tt_STOP_PD= digitalRead(P_STOP_PD);           // đọc trạng thái nút nhấn Stop và phao dưới
  tt_PHAOT= digitalRead(P_PHAOT);               // đọc trạng thái phao trên
  tt_TEMP= digitalRead(P_TEMP);                 // đọc trạng thái báo lỗi quá tải từ biến tần
  tt_RSTI= digitalRead(P_RSTI);                 // đọc trạng thái nút nhấn Rst
  TOCDO=map(analogRead(P_VR),750,1023,1,5);     // biến tốc độ để hiển thị lên hệ thống giám sát
  if(TOCDO<1){
    TOCDO=1;
    }

if((tt_START==LOW) and (tt_STOP_PD==HIGH) and (x!=1)and(tt_TEMP==HIGH)){      // nhấn nút START khi động cơ đang không có lệnh chạy
  delay(200);
  TAY=1;                           // vào chế độ chạy nút nhấn                                                     
  ONL=0;
  PHAO=0;
  delay(20);
  }
  
if((tt_START==HIGH) and (tt_STOP_PD==LOW) and (x==1)and(tt_TEMP==HIGH)){        //   nhấn nút STOP hoặc nước xuống thấp khi động cơ đang có lệnh chạy
  delay(200);
  TAY=2;                           // tắt tất cả
  ONL=2;
  PHAO=2;
  delay(20);
  }
if((tt_PHAOT==LOW) and (tt_STOP_PD==HIGH) and (x!=1)and(tt_TEMP==HIGH)){       // nước lên mức trên khi động cơ đang không có lệnh chạy 
  delay(10000);
  PHAO=1;                         // đợi 10s vào trạng thái chạy phao
  TAY=0;
  ONL=0;
  Blynk.virtualWrite(V7,1);      // gửi thông báo mức nước đang trên cao
  delay(20);
  }

if((tt_PHAOT==HIGH) and (tt_STOP_PD==LOW) and (x==1)and(tt_TEMP==HIGH)){     // nước xuống thấp khi động cơ đang có lệnh chạy
  delay(200);
  PHAO=2;                       // dừng tất cả
  TAY=2;                          
  ONL=2; 
  delay(20);
  }
  
if ((TAY==1)and(tt_TEMP==HIGH)){                       // hiển thị vào chế dộ chạy tay
    lcd.setCursor(0,0);
    lcd.print("CHE DO: NUT NHAN");
    lcd_app.print(0,0,"CHE DO: NUT NHAN");
    x=1;
    y=1;
  }
  
if((ONL==1)and(tt_TEMP==HIGH)){                         // hiển thị vào chế độ chạy onl
    lcd.setCursor(0,0);
    lcd.print("CHE DO: WIFI    ");
    lcd_app.print(0,0,"CHE DO: WIFI    ");
    x=1;
    y=1;
  }

if ((PHAO==1)and(tt_TEMP==HIGH)){                         // hiển thị vào chế độ chạy phao
    lcd.setCursor(0,0);
    lcd.print("CHE DO: PHAO    ");
    lcd_app.print(0,0,"CHE DO: PHAO    ");
    x=1;
    y=1;
}

if(x==1){
    digitalWrite(P_ON,HIGH);
    lcd.setCursor(0,1);                                             // lệnh chạy động cơ 
    lcd.print("CAP TOC DO: "+ String(TOCDO)+"   ");
    lcd_app.print(0,1,"CAP TOC DO: " +String(TOCDO)+"   ");
    Blynk.virtualWrite(V3,TOCDO);
    Blynk.virtualWrite(V4,1); 
}
else {
  digitalWrite(P_ON,LOW);
  Blynk.virtualWrite(V3,0);
  Blynk.virtualWrite(V4,0);
      }
 
if((TAY==2)and(ONL==2)and(PHAO==2)and(tt_TEMP==HIGH)){         //vào trạng thái dừng tất cả                      
    x=2; 
    digitalWrite(P_ON,LOW);
 if(y==1){
    lcd.clear();
    lcd_app.clear();  
  for(int i=0;i<16;i++){    // vòng lặp để hiển thị lần lượt 16 kí tự -
    lcd.setCursor(i,0);
    lcd.print("-");
    lcd.setCursor(i,1);
    lcd.print("-");
    lcd_app.print(i,0,"-");
    lcd_app.print(i,1,"-");
    delay(50);           // thời gian delay tổng là 1s đủ để động cơ dừng hẳn
                             }
     y=2;                       // trạng thái 
            }
                      }

//-------------------------- hiển thị chế độ đang dừng
if (y==2){
    lcd.setCursor(0,0);
    lcd.print("DUNG DONG CO    ");
    lcd.setCursor(0,1);
    lcd.print("CAP TOC DO: 0   ");
    lcd_app.print(0,0,"DUNG DONG CO    ");
    lcd_app.print(0,1,"CAP TOC DO: 0   ");
    Blynk.virtualWrite(V3,0);                           // hiển thị tốc độ động cơ =0 
    Blynk.virtualWrite(V4,0); 
    Blynk.virtualWrite(V5,0);
    Blynk.virtualWrite(V7,0);
    
}
//------------------------------------- RESET ---------------------------------                    
if(tt_RSTI==LOW){           // nhấn nút RESET => tất cả các giá trị quay về giá trị khởi tạo             
    delay(300);
    ONL=0;    
    TAY=0;    
    PHAO=0;  
    x=0;
    y=3;                      // vào trạng thái reset
    rst=1;
    delay(50);
      } 

if(rst==1){                         //bắt đầu reset hệ thống
    ONL=0;    
    TAY=0;    
    PHAO=0;  
    x=0;
    y=3;  
    digitalWrite(P_ON,LOW);           // tắt tín hiệu chạy
    digitalWrite(P_RSTO,HIGH);        // bật tín hiệu rst
    delay(100);
    rst=0;
  }
 else{
  digitalWrite(P_RSTO,LOW);
  }  


//-------------------- chế độ chờ, sau khi rst
if (y==3){
  lcd.setCursor(0,0);
  lcd.print("CO DIEN TU M.HOA  ");
  lcd.setCursor(0,1);
  lcd.print("   0397699040   ");
  lcd_app.print(0,0,"CO DIEN TU M.HOA");
  lcd_app.print(0,1,"   0397699040   ");
  }          
//--------------------------- trạng thái báo quá tải động cơ
if (tt_TEMP==LOW){                        // role nhiệt đóng cấp gnd 
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("! ! CANH BAO ! !");
    lcd.setCursor(0,1);
    lcd.print("DONG CO QUA TAI ");   
    lcd_app.print(0,0,"! ! CANH BAO ! !");
    lcd_app.print(0,1,"DONG CO QUA TAI ");
    Blynk.virtualWrite(V3,0);             // hiển thị tốc độ động cơ =0
    Blynk.virtualWrite(V4,0);             // trạng thái động cơ trên webdashboard (Blynk IOT)
    Blynk.virtualWrite(V5,1);             // trạng thái nhiệt trên webdashboard (Blynk IOT) 
    x=0;                                   // đưa tất cả các biến về giá trị khởi tạo
    y=0;
    TAY=0;
    PHAO=0;
    ONL=0;
    }
 else{ 
    Blynk.virtualWrite(V5,0); 
 }
 Serial.println("110102");
 Serial.println(x);
 Serial.println(y);
}
