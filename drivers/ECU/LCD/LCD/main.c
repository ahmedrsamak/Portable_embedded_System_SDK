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
	obj.data_pin[0]=4;
    obj.data_pin[1]=5;
    obj.data_pin[2]=6;
	obj.data_pin[3]=7;
	obj.E_pin=6;
	obj.RS_pin=7;
	obj.ctrl_port=PORTA;
	obj.data_port=PORTB;
	lcd_init(&obj);
	lcd_out(&obj,1,1,"samak");
    while (1) 
    {
    }
}

