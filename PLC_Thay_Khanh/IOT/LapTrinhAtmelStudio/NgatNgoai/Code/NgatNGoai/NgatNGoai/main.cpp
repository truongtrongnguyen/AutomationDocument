/*
 * NgatNGoai.cpp
 *
 * Created: 1/8/2024 9:46:03 PM
 * Author : DELL
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0XFF; // OUTPUT
	PORTA = 0X00; // Kích m?c cao nên cho nó v? 0V
	DDRD = 0B00000001; // Chân D0 là OUTPUT, D2  là INPUT
	PORTD = (0<<PIND0); // Chân D0 là 0v
	GICR |= (1<<INT0); // Kích hoat chân ngat là INT0 hoac INT1
	MCUCR |= (1<<ISC01); // Chon che do ngat
	// Neu  chan ngat la INT2 thi phai khai bao la MCUSR
	sei();
    while (1) 
    {
		PORTA = 0X01;
		_delay_ms(200);
		for(int i = 0; i <7; i++)
		{
			PORTA = PORTA<< 1;
			_delay_ms(200);
		}
    }
}

ISR(INT0_vect)
{
	if((PIND & (1<<PIND2))==0)	// N?u có nh?n nút ng?t D2
	{
		PORTD = 0X01;
		_delay_ms(500);
		PORTD = 0X00;
	}
}

