/*
 * Code.cpp
 *
 * Created: 1/11/2024 5:27:31 AM
 * Author : DELL
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
void Delay();


int main(void)
{
    /* Replace with your application code */
	DDRB = 0XFF;
    while (1) 
    {
		PORTB = 0XFF;
		Delay();
		PORTB = 0X00;
		Delay();
    }
}

void Delay()
{
	TCNT0 = 177; // Luu gia tri dem
	TCCR0 = (1<<CS00)|(1<<CS02); // precaller1024
	while((TIFR&0X01)==0)	// Neu Bit0 cua thanh ghi TIFR = 0 thi no chua tran
	{
	
	}
	TCCR0 = 0;
	TIFR = 0X01;
}

