/*
 * code.cpp
 *
 * Created: 1/21/2024 7:54:59 PM
 * Author : DELL
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRB = 0x08; // PB3(OC0) as Output
	while(1)
	{
		OCR0 = 99;
		TCCR0 = (1<<WGM01)|(1<<CS01)|(1<<CS00)|(1<<COM00)|(1<<COM01);
		while((TIFR&0x02)==0);
		TIFR = 0x02;
		
		OCR0 = 69;
		TCCR0 = (1<<WGM01)|(1<<CS01)|(1<<CS00)|(1<<COM01);
		while((TIFR&0x02)==0);
		TIFR = 0x02;
	}
}
		
		
		
		
// TEST1
//DDRB = DDRB|(1<<3); // PB3(OC0) as Output
//TCCR0 = 0x19 // CTC mode, toggle on compare match clk-no-prescaler
//OCR0 = 200; // value compare
//while (1)
//{
//}

// TEST2
//DDRB |= (1<<3);
//while(1)
//{
//OCR0 = 69;// thanh ghi so sanh
//TCCR0 = 0x39;	// CTC set on match, no prescaler	- Che do hoat dong
//while((TIFRF&(1<<OCF0))==0);	// monitor OCF0 flag	- kiem tra gia tri tren thanh timer/couter co bang gia tri OCR0 chua
//TIFR =  (1<<OCF0); // clear OCF0 by writing 1
//
//OCR0 = 99;
//TCCR0 =0x29; // CTC clear on match, no prescaler
//while((TIFRF&(1<<OCF0))==0);	// monitor OCF0 flag	- kiem tra gia tri tren thanh timer/couter co bang gia tri OCR0 chua
//TIFR =  (1<<OCF0); // clear OCF0 by writing 1
//}