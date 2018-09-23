/*
 * hal_uart.c
 *
 * Created: 9/23/2018 2:18:18 PM
 *  Author: ahmed
 (*(volatile port_base*)(port-1))
 */ 
#include "hal_uart.h"
void uart_init(u32 baud_rate,parity_sel parity,stop_bits_sel stop_bits)
{
	 (*(volatile port_base*)(UCSRB)) = (1 << 4) | (1 << 3); // Enable RX and TX pins
	 (*(volatile port_base*)(UCSRC)) |= (3<<1); // 8 bits mode
	 (*(volatile port_base*)(UCSRA)) |=(1<<1); // double speed active
	 (*(volatile port_base*)(UCSRC)) |=(1<<7); // select reg UCSRC
	 (*(volatile port_base*)(UCSRC)) |=(parity<<4); // select parity
	 (*(volatile port_base*)(UCSRC)) |=(stop_bits<<3); // select stop_bits
	  (*(volatile port_base*)(UCSRC)) |=(1<<7); // select reg UCSRC
	  (*(volatile port_base*)(UCSRC)) &=~(1<<6);
	  (*(volatile port_base*)(UBRRL)) &=~(1<<7);
	  (*(volatile port_base*)(UBRRL)) = (u8)(( (F_CPU / (8L * baud_rate) ))); // set baud_rate
	  (*(volatile port_base*)(UBRRH)) = (u8)((( (F_CPU / (8L * baud_rate))))>>8); // set baud_rate
}
void uart_write_byte(char write_byte)
{
while(!((*(volatile port_base*)(UCSRA)) & (1<<5)));// handle it with interrupt to prevent delay
(*(volatile port_base*)(UDR)) = write_byte;

}