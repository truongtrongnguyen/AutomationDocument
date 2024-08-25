///*
 //* codeLCD_4Bit.cpp
 //*
 //* Created: 3/10/2024 11:36:34 PM
 //* Author : DELL
 //*/ 
//
//#define F_CPU 8000000L
//#include "util/delay.h"
//#include <avr/io.h>
//
//#define LCD_Command_Port PORTC	// Define LCD command port direction register
//#define LCD_Data_Port PORTC		// define lcd Data port
//
//#define RS 0	// define register select (Data/command reg.)pin
//#define EN 1	// define Enable signal pin
//
//void LCD_Command(unsigned char);	// Ham Gui Lenh
//void LCD_Char(unsigned char);	// Ham Gui 1 ky tu Data
//void LCD_Init(void);
//void LCD_String (char*);
//
//
//int main(void)
//{
    ///* Replace with your application code */
	//LCD_Init();
	//LCD_String("Hello Work");
	//
    //while (1) 
    //{
    //}
//}
//
//void LCD_Command(unsigned char cmnd)
//{
	//// Dau tien gui 4 bit co trong so cao nhung khong anh huong den cac Port con lai
	////LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	//
	//LCD_Command_Port &= ~(1<<RS);
	//LCD_Data_Port = (cmnd & 0xF0);
	//// Tao xung xuong cho chan E de cho phep ghi lenh vao LCD
	//LCD_Command_Port |= (1<<EN);	// EN = 1
	//_delay_ms(1);
	//LCD_Command_Port &= ~(1<<EN);	// EN = 0
	//
	//_delay_ms(200);
	//
	//// Tiep Theo Gui 4 bit trong so thap
	//LCD_Data_Port = ((cmnd & 0x0F)<<4);
	//// Tao xung xuong cho chan E de cho phep ghi lenh vao LCD
	//LCD_Command_Port |= (1<<EN);	// EN = 1
	//_delay_ms(1);
	//LCD_Command_Port &= ~(1<<EN);	// EN = 0
	//_delay_ms(2);
		//
//}
//
//void LCD_Char(unsigned char char_data)
//{
	//
	//LCD_Command_Port |= (1<<RS);
	//LCD_Data_Port = (char_data & 0xF0);
	//// Tao xung xuong cho chan E de cho phep ghi lenh vao LCD
	//LCD_Command_Port |= (1<<EN);	// EN = 1
	//_delay_ms(2);
	//LCD_Command_Port &= ~(1<<EN);	// EN = 0
	//
	//_delay_ms(200);
	//
	//LCD_Data_Port = ((char_data & 0x0F)<<4);
	//// Tao xung xuong cho chan E de cho phep ghi lenh vao LCD
	//LCD_Command_Port |= (1<<EN);	// EN = 1
	//_delay_ms(1); 
	//LCD_Command_Port &= ~(1<<EN);	// EN = 0
	//_delay_ms(2);
//}
//
//void LCD_Init(void)
//{
	//LCD_Data_Port |= (1<<PC4) | (1<<PC5) | (1<<PC6) | (1<<PC7);
	//_delay_ms(20);
	//
	//LCD_Command(0x28);
	//LCD_Command(0x02);
	//LCD_Command(0x0C);
	//LCD_Command(0x01);
	//_delay_ms(2);
//}
//
//void LCD_String(char *str)
//{
	//for(int i = 0; str[i] != 0; i++)
	//{
		//LCD_Char(str[i]);
	//}
//}


#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL // Assuming a 8MHz clock

#define EN BIT7 // P2.7
#define RS BIT6 // P2.6
#define DATA 0x3C // P2.2 to P2.5

#define delay_ms(x) __delay_cycles((long) x* 1000)
#define delay_us(x) __delay_cycles((long) x)

void lcdInit() {
	delay_ms(100); // Wait for 100ms after power is applied.

	P2DIR = EN + RS + DATA; // Make pins outputs

	P2OUT = 0x03; // Start LCD (send 0x03)
	lcdTriggerEN(); // Send 0x03 3 times at 5ms then 100 us
	delay_ms(5);
	lcdTriggerEN();
	delay_ms(5);
	lcdTriggerEN();
	delay_ms(5);
	P2OUT = 0x02; // Switch to 4-bit mode
	lcdTriggerEN();
	delay_ms(5);
	lcdWriteCmd(0x28); // 4-bit, 2 line, 5×8
	lcdWriteCmd(0x08); // Instruction Flow
	lcdWriteCmd(0x01); // Clear LCD
	lcdWriteCmd(0x06); // Auto-Increment
	lcdWriteCmd(0x0C); // Display On, No blink
}

void lcdTriggerEN() {
	P2OUT |= EN;
	P2OUT &= ~EN;
}

void lcdWriteData(unsigned char data) {
	P2OUT |= RS; // Set RS to Data
	P2OUT = (P2OUT & 0xF0) + (data >> 4); // Upper nibble
	lcdTriggerEN();
	P2OUT = (P2OUT & 0xF0) + (data & 0x0F); // Lower nibble
	lcdTriggerEN();
	delay_us(50); // Delay > 47 us
}

void lcdWriteCmd(unsigned char cmd) {
	P2OUT &= ~RS; // Set RS to Command
	P2OUT = (P2OUT & 0xF0) + (cmd >> 4); // Upper nibble
	lcdTriggerEN();
	P2OUT = (P2OUT & 0xF0) + (cmd & 0x0F); // Lower nibble
	lcdTriggerEN();
	delay_ms(5); // Delay > 1.5ms
}

void lcdSetText(char* text, int x, int y) {
	int i = 0;
	if (x < 16) {
		x |= 0x80; // Set LCD for first line write
		if (y == 1) x |= 0x40; // Set LCD for second line write
		lcdWriteCmd(x);
	}
	while (text[i] != '\0') {
		lcdWriteData(text[i]);
		i++;
	}
}

int main(void) {
	WDTCTL = WDTPW + WDTHOLD; // Stop Watchdog
	P2SEL = 0xC0; // To make P2.6,P2.7 GPIO pins
	lcdInit(); // Initialize LCD
	lcdSetText("HelloWork", 0, 0); // Print "HelloWork" on the first line
	return 0;
}
