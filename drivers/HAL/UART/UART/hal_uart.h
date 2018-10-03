/*
 * hal_uart.h
 *
 * Created: 9/23/2018 2:18:32 PM
 *  Author: ahmed
 */ 


#ifndef HAL_UART_H_
#define HAL_UART_H_

#include "common.h"

typedef enum
{
	NONE,
	EVEN=2,
	ODD,
}parity_sel;

typedef enum
{
	ONE_BIT,
	TWO_BITS,
}stop_bits_sel;

void uart_init(u32 baud_rate,parity_sel parity,stop_bits_sel stop_bits);
void uart_write_byte(char write_byte);
char uart_read_byte();
void uart_write_text(char * write_text);



#endif /* HAL_UART_H_ */