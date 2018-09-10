/*
 * LCD.c
 *
 * Created: 9/10/2018 2:09:53 AM
 * Author : ahmed
 */ 
#include "hal_lcd.h"
int main(void)
{
   dio_set_port_dir(PORTA,OUTPUT);
   dio_write_pin(PORTA,5,HIGH);
    while (1) 
    {
    }
}

