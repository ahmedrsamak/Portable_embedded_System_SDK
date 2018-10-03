/*
 * UART.c
 *
 * Created: 9/23/2018 2:17:45 PM
 * Author : ahmed
 */ 
#include "hal_uart.h"
char x;
int main(void)
{
    uart_init(115200,NONE,ONE_BIT);
	uart_write_text("Start");
    while (1) 
    {
		x=uart_read_byte();
		uart_write_byte(x);
    }
}