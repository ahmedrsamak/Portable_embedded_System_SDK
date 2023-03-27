/*
 * I2C.c
 *
 * Created: 9/12/2018 10:02:42 PM
 * Author : ahmed
 */ 


#include "twi.h"
#include <util/delay.h>
int main(void)
{
    TWI_Init(500,0x01);
	TWI_Start();
	TWI_Write(0xF2);
	TWI_Write(0xFE);
	TWI_Write(0xFA);
	TWI_Write(0xFD);
	TWI_Write(0xF8);
	TWI_Stop();
	//_delay_ms(5000);
	TWI_Start();
	TWI_Write(0xF0);
	TWI_Write(0xF2);
	TWI_Write(0xF4);
	TWI_Write(0xF6);
	TWI_Write(0xF8);
	TWI_Stop();
    while (1) 
    {
    }
}

