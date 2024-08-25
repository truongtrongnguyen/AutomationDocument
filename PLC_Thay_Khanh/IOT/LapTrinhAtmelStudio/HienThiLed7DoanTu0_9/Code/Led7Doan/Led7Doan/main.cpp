/*
 * Led7Doan.cpp
 *
 * Created: 1/9/2024 8:35:12 PM
 * Author : DELL
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
unsigned char MaDB[10] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};
// Ma hien thi so tu 0 den 9, Kich muc thap Anot chung


int main(void)
{
    /* Replace with your application code */
	DDRC = 0XFF;
	PORTC = 0XFF; 
    while (1) 
    {
		for(int i = 0; i<10; i++)
		{
			PORTC = MaDB[i];
			_delay_ms(500);
		}
    }
}

