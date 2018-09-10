/*
 * LCD.c
 *
 * Created: 9/10/2018 2:09:53 AM
 * Author : ahmed
 */ 
#include "hal_lcd.h"
config_lcd_pin obj;
int main(void)
{
	obj.data_pin[0]=1;
    obj.data_pin[1]=3;
    obj.data_pin[2]=6;
	obj.data_pin[3]=7;
	obj.port=PORTA;
	lcd_init(&obj);
    while (1) 
    {
    }
}

