/*
 * Code.cpp
 *
 * Created: 3/10/2024 10:42:46 PM
 * Author : DELL
 */ 

#define F_CPU 8000000L
#include "util/delay.h"
#include <avr/io.h>

#define LCD_Data_Dir DDRD	// Define LCD data port direction
#define LCD_Command_Dir DDRC	// Define LCD command port direction register
#define LCD_Data_Port PORTD		// define lcd Data port
#define LCD_Command_Port PORTC

#define RS 0	// define register select (Data/command reg.)pin
#define RW 1	// define Read/Write signal pin
#define EN 2	// define Enable signal pin

void LCD_Command(unsigned char cmnd);	// Ham Gui Lenh
void LCD_Char(unsigned char char_data);	// Ham Gui 1 ky tu Data
void LCD_String(char *str);


int main(void)
{
    /* Replace with your application code */
	
	// Khoi tao Output
	LCD_Data_Dir = 0xFF;	// Cac chan Gui Data
	LCD_Command_Dir |=(1<<RW)|(1<<RS)|(1<<EN);
	
	// Khoi tao LCD - Cac ma Lenh co trong Image
	LCD_Command(0x38);	// Khai bao LCD module 8bit, 2dong
	LCD_Command(0x0C);	// Bat hien thi, tat con tro
	LCD_Command(0x01);	// Bat Man hinh LCD
	
	LCD_String("Hello Word!");
	LCD_Command(0xC0);	// Di chuyen con tro xuong hang thu 2
	LCD_String("GoodBye");
	
    while (1) 
    {
    }
}

void LCD_Command(unsigned char cmnd)
{
	LCD_Command_Port &= ~(1<<RW);	// RW = 0
	LCD_Command_Port &= ~(1<<RS);	// RS = 0
	LCD_Data_Port = cmnd;			// Gui Byte lenh ra cac chan Port
	
	// Tao xung xuong cho chan E de cho phep ghi lenh vao LCD
	LCD_Command_Port |= (1<<EN);	// EN = 1
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<EN);	// EN = 0
	_delay_ms(3);
}

void LCD_Char(unsigned char char_data)
{
	LCD_Command_Port &= ~(1<<RW);	// RW = 0
	LCD_Command_Port |= (1<<RS);	// RS = 1
	LCD_Data_Port = char_data;
	
	// Tao xung xuong cho chan E de cho phep ghi lenh vao LCD
	LCD_Command_Port |= (1<<EN);	// EN = 1;
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<EN);	// EN = 0;
	_delay_ms(3);
}

void LCD_String(char *str)
{
	for(int i = 0; str[i] != 0; i++)
	{
		LCD_Char(str[i]);
	}
}