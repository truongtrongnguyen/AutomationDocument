/*
 * LedDichBit.cpp
 *
 * Created: 1/7/2024 7:52:04 PM
 * Author : DELL
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0XFF;	// Definition Pin as OUTPUTS
	PORTA = 0X00;	// Các chân ngõ ra là 0v
	
    while (1) 
    {
		//PORTA = 0b11100111;
		//for(int i = 3; i >= 0; i--)
		//{
			//PORTA &= ~(1<<(i));
			//PORTA &= ~(1<<(7-i));
			//_delay_ms(200);
			//PORTA |= (1<<i);
			//PORTA |= (1<<(i-7));
		//}
		
		PORTA = 0B00000001;
		_delay_ms(200);
		for(int i = 0; i<7; i++)
		{
			PORTA = PORTA << 1;
			_delay_ms(200);
		}
    }
}

