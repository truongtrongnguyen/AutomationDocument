/*
 * Code.cpp
 *
 * Created: 1/22/2024 9:37:44 PM
 * Author : DELL
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/sfr_defs.h>
unsigned char MaDB[12] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90, 0X9C, 0XC6};
// Ma hien thi so tu 0 den 9, Kich muc thap Anot chung
int adc_val;

void HienThi(unsigned int x)
{
	uint16_t  temp, HangChuc, DonVi;
	// tach bien va luu vao cac bien ch, dv
	temp = x;
	HangChuc = temp/10;
	DonVi = temp%10;
	
	for (int i = 0; i<20; i++)
	{	
		// kich chan DK hien thi led so 1
		PORTD = 0X00;
		PORTD = (1<<PIND0);
		PORTB = MaDB[HangChuc];
		_delay_ms(1);
		
		//// kich chan DK hien thi led so 2
		PORTD = 0X00;
		PORTD = (1<<PIND1);
		PORTB = MaDB[DonVi];
		_delay_ms(1);
		
		// Hien thi chu oC
		PORTD = 0X00;
		PORTD = (1<<PIND2);
		PORTB = MaDB[10];
		_delay_ms(1);
		
		PORTD = 0X00;
		PORTD = (1<<PIND3);
		PORTB = MaDB[11];
		_delay_ms(1);
	}
}

uint16_t Read_ADC(unsigned int kenh_adc)
{
	ADMUX = kenh_adc|(1<<REFS0);	// Chon dien ap tham chieu (5v) va kenh de chuyen doi
	ADCSRA |=(1<<ADSC);		// Khoi dong chuyen doi ADC
	loop_until_bit_is_set(ADCSRA, ADIF);	// Kiem tra qua trinh chuyen doi, doc bit ADIF cua thanh ghi ADCSRA khi nao len 1 la qua trinh chuyen doi thanh cong
	return ADCW;	// tra ve gia tri chuyen doi do vao thanh ghi ADCW
}



int main(void)
{
    /* Replace with your application code */
	ADMUX |= (1<<REFS0);	// Chon dien ap tham chieu chan AVCC
	ADCSRA |= (1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);
	// Bit ADEN la bat dau su dung chuyen doi ADC
	// ADPS0 - ADPS1 la su dung he so chia xung nhip. chia 2-4-8-16-32-64-128
	
	
	DDRB = 0XFF;
	DDRD = (1<<PIND0)|(1<<PIND1)|(1<<PIND2)|(1<<PIND3); // DDRA = 0B00000100
	
	
    while (1) 
    {
		adc_val =  (int)(Read_ADC(0)/2.05);	// 0 la kenh so 0
		//adc_val =  (int)(Read_ADC(0)/3.41);	// 0 la kenh so 0
		HienThi(adc_val);
    }
}

