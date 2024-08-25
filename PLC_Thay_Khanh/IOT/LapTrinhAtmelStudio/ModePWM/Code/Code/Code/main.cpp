/*
 * Code.cpp
 *
 * Created: 1/12/2024 5:40:47 AM
 * Author : DELL
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/delay.h>

void PWM_init()
{
	DDRB = (1<<PB3); // Set OC0 pin as OUPUT
	// Set fast PWM mode with non-inverted output
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00); // Chon mode fast PWM, NON-INVERTED, PRECALLER	
}


int main(void)
{
    /* Replace with your application code */
	unsigned char duty;
	PWM_init();
    while (1) 
    {
		for(duty = 0; duty<255; duty++)
		{
			OCR0 = duty;	// Thay doi gia tri se thay doi do rong xung
			_delay_ms(10);
		}
		for(duty = 255; duty>0; duty--)
		{
			OCR0 = duty;
			_delay_ms(10);
		}
    }
}

