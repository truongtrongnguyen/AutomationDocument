/*
 * Code.cpp
 *
 * Created: 1/10/2024 7:54:43 PM
 * Author : DELL
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
unsigned char MaDB[10] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};
volatile unsigned long dem = 0;
unsigned int Count = 0;

void HienThi(unsigned int x)
{
	uint16_t temp, HangChuc, DonVi;
	temp = x;
	HangChuc = temp/10;
	DonVi = temp%10;
	
	for(int i = 0; i<2; i++)
	{
		PORTA = 0X00;
		PORTA = (1<<PINA0);
		PORTB = MaDB[HangChuc];
		_delay_ms(0.1);
		
		PORTA = 0X00;
		PORTA = (1<<PINB1);
		PORTB = MaDB[DonVi];
		_delay_ms(0.1);
	}
}


int main(void)
{
    /* Replace with your application code */
	DDRA = (1<<PINA0) | (1<<PINA1);
	PORTA = (0<<PINA0) | (0<<PINA1);
	DDRB = 0XFF;
	PORTB = 0x00;
	
	TCCR0 = (1<<CS00) | (1<<CS01);
	TCNT0 = 130;
	TIMSK|= (1<<TOIE0);
	sei();
    while (1) 
    {
		HienThi(Count);
		if(dem >= 500)
		{
			if(Count < 59)
			{
				Count++;
			}
			else
			{
				Count = 0;
			}
			dem = 0;
		}
    }
}
ISR(TIMER0_OVF_vect)
{
	TCNT0 = 130;
	dem++;
}

