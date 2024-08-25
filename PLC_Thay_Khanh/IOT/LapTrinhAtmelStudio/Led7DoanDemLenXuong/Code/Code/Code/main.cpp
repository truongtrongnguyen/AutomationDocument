/*
 * Code.cpp
 *
 * Created: 1/9/2024 9:52:35 PM
 * Author : DELL
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
unsigned char MaDB[10] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};
// Ma hien thi so tu 0 den 9, Kich muc thap Anot chung

void HienThi(unsigned int x)
{
	uint16_t  temp, HangChuc, DonVi;
	// tach bien va luu vao cac bien ch, dv
	temp = x;
	HangChuc = temp/10;
	DonVi = temp%10;
	
	// kich chan DK hien thi led so 1
	PORTA = 0X00;
	PORTA = 0B0000001;
	PORTB = MaDB[HangChuc];
	_delay_ms(1);
	
	//// kich chan DK hien thi led so 2
	PORTA = 0X00;
	PORTA = 0B00000010;
	PORTB = MaDB[DonVi];
	_delay_ms(1);
}


int main(void)
{
    /* Replace with your application code */
	DDRB = 0XFF;
	DDRA = (1<<PINA0)|(1<<PINA1); // DDRA = 0B00000011
	PORTB = 0X00;
	PORTA = 0X00;
	DDRC = (0<<PINC0)|(0<<PINC1); // DDRC = 0B00000000 --> Khai Bao 2 chan nut nhan
	unsigned int i = 0;
	
    while (1) 
    {
		HienThi(i);
		if((PINC & (1<<PINC0))==0)
		{
			// Vong lap xu li dang trong qua trinh nhan nut
			while((PINC & (1<<PINC0))==0)
			{
				HienThi(i);
			}
			if(i<99)
			{
				i++;
				HienThi(i);
			}
			else
			{
				i = 0;
				HienThi(i);
			}
		}
		else if((PINC&(1<<PINC1))==0)
		{
			// Vong lap xu li dang trong qua trinh nhan nut
			while((PINC & (1<<PINC1))==0)
			{
				HienThi(i);
			}
			if(i>0)
			{
				i--;
				HienThi(i);
			}
			else
			{
				i = 99;
				HienThi(i);
			}
		}
    }
}

