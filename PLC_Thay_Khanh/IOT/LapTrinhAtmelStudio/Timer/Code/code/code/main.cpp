/*
 * code.cpp
 *
 * Created: 1/10/2024 5:45:16 AM
 * Author : DELL
 */ 

#define F_CPU 16000000UL;
#include <avr/io.h>
#include <avr/interrupt.h>
volatile unsigned long dem = 0; 


int main(void)
{
    /* Replace with your application code */
	DDRA = 0X01;
	PORTA = 0X00;
	
	TCCR0 = (1<<CS00) | (1<<CS01); // Precaller = 64, chia cho 64
	TCNT0 = 130;	// Lay ((8000000 * 0.001ms) /64) - 255 --> Nó se dem tu 130 den 255 roi chay vao timer
	TIMSK |= (1<<TOIE0);	// Khi Timer dem du thi no cho phep chay vao ham ngat
	sei();
	
	
    while (1) 
    {
		if(dem >= 500)
		{
			PORTA = ~PORTA; // Dao bit 
			dem = 0;
		}
    }
}
ISR(TIMER0_OVF_vect)
{
	TCNT0 = 130;	// Gia tri dem tu 130 den 255, neu khong luu 130 thi no se dem tu 0 den 255
	dem++;
}

