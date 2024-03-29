/*
 * uart.c
 *
 * Created: 9/23/2018 2:18:18 PM
 *  Author: ahmed
 (*(volatile port_base*)(port-1))
 */ 
#include "uart.h"
void uart_init(u32 baud_rate,parity_sel parity,stop_bits_sel stop_bits)
{
	UCSRB = (1 << 4) | (1 << 3); // Enable RX and TX pins
	 UCSRC |= (3<<1); // 8 bits mode
	 UCSRA |=(1<<1); // double speed active
	 UCSRC |=(1<<7); // select reg UCSRC
	 UCSRC |=(parity<<4); // select parity
	 UCSRC |=(stop_bits<<3); // select stop_bits
	 UCSRC |=(1<<7); // select reg UCSRC
	 UCSRC &=~(1<<6);
	 UBRRL &=~(1<<7);
	 UBRRL = (u8)(( (F_CPU / (8L * baud_rate) ))); // set baud_rate
	 UBRRH = (u8)((( (F_CPU / (8L * baud_rate))))>>8); // set baud_rate
}

void uart_write_byte(char write_byte)
{
	while(!(UCSRA & (1<<5)));// handle it with interrupt to prevent delay
	UDR = write_byte;
}

void uart_write_num(s16 num)
{
	u8 ArrayIndex = 0;
	char s8DisplayStr[6] = {0};
	/* convert number to ASCII */

	itoa(num, s8DisplayStr, 10);

	for(ArrayIndex = 0; s8DisplayStr[ArrayIndex] != 0; ArrayIndex++)
	{
		uart_write_byte(s8DisplayStr[ArrayIndex]);
	}		
}

char uart_read_byte()
{
	while (! ((UCSRA) & (1 << 7)));
	return UDR;
}
void uart_write_text(char * write_text)
{
	 while(*write_text>0)
	 {
		 uart_write_byte(*write_text++);
	 }
}