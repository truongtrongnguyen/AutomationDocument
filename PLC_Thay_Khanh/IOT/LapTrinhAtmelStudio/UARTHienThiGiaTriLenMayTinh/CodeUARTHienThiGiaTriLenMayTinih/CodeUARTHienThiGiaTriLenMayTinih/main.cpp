/*
 * CodeUARTHienThiGiaTriLenMayTinih.cpp
 *
 * Created: 3/10/2024 12:02:42 AM
 * Author : DELL
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>	
volatile int count = 0;

void UART_Init()
{
	// Set baud: 9600 equivalent to f=8MHZ
	UBRRH = 0;
	UBRRL = 51;
	UCSRA = 0x00;
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);	// Set up data frame: 1 bit start - 1 bit stop - no parity - 8 bit frame
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);	// Enable rx - tx, and enable interrupt when received data
}

// Received data
unsigned char usart_getchar()
{
	while(!(UCSRA & (1<<RXC))); // bit RXC tren UCSRA cho biet qua trinh nhan ket thuc hay chua
	return UDR; // return value in thanh ghi  du lieu
}

// Send Data
void usart_putdata(char data)
{
	// wait for empty transmit buffer
	while(!(UCSRA & (1<<UDRE))); // kiem tra bit UDRE tren thanh UCSRA co bang 0 hay khong Neu khac 0 tra ve 0 that while
	
	// put data into buffer, sends the data
	UDR = data; // Ghi gia tri len thanh ghi du lieu
}

// gui a string	
void usart_write(char *string)
{
	for (int i =0; i<255; i++)
	{ 
		if(string[i] != 0)
		{
			usart_putdata(string[i]);
		}
		else
		{
			break;
		}
	}
}

// nhan a string
void usart_read(char *string)
{
	char temp;
	for (int i =0; i<9; i++)
	{
		temp = usart_getchar();
		*string = temp;
		string++;
	}	
}


int main(void)
{
    /* Replace with your application code */
	UART_Init();
	#pragma region ConfigProgramInterrupt

	/*
	The line GICR |= (1<<ISC2); is used to enable an external interrupt on the ATmega microcontroller. 
	This line specifically enables the interrupt for INT2, which is the external interrupt request 2. 
	The GICR register is used to enable or disable external interrupts on the ATmega microcontroller.
	The ISC2 bit in the GICR register is used to control the interrupt sense control for INT2.
	*/
	GICR |= (1<<INT2);
	MCUCSR |=(1<<ISC2);
	
	
	//The line DDRB = (0<<PB2); is intended to configure the Data Direction Register for 
	//Port B (DDRB) on an AVR microcontroller, specifically setting the direction of pin PB2 to input.
	 //However, there seems to be a misunderstanding in the operation. The correct operation to set PB2 
	 //as an input is DDRB &= ~(1<<PB2);.
	DDRB = (0<<PB2);
	
	//The sei() function is used to enable interrupts by setting the global interrupt mask. 
	//This function is part of the AVR Libc library and is used in AVR microcontroller programming. 
	//When sei() is called, it sets the I bit in the Status Register (SREG) to 1, allowing interrupts to be processed
	sei();
	#pragma endregion ConfigProgramInterrupt
	
    while (1) 
    {
    }
}

// Ham Ngat INT2
ISR(INT2_vect)
{
	char INT2_VALUE[20];
	count++;
	
	sprintf(INT2_VALUE, "%d\n\r", (int)count);
	_delay_ms(1000);
	// USART (Universal Synchronous/Asynchronous Receiver-Transmitter) communication
	usart_write("INT2_VALUE");
	usart_write(INT2_VALUE);
}