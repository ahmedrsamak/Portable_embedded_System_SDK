/*
 * ADC.c
 *
 * Created: 2/22/2023 10:21:11 PM
 * Author : ahmed
 */ 

#include "Driver/common.h"
#include "Driver/adc.h"
#include "Driver/uart.h"


int main(void)
{
adc_init(INTERNAL_REF);
uart_init(9600,NONE,ONE_BIT);
uart_write_text("Start");
    while (1) 
    {
		uart_write_num(adc_read(0));
		_delay_ms(500);
		uart_write_text("\r\n");
		
    }
}

