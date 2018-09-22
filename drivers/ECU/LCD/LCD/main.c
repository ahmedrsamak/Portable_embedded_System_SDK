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
	
	//lcd_cmd(&obj,LCD_ON_CURSOR_OFF);
	lcd_cmd(&obj,LCD_CLEAR);
	lcd_out_str(&obj,1,1,"samak");
	lcd_out_str(&obj,2,1,"samak");
	lcd_out_str(&obj,1,1,"1234567891234567");
	lcd_out_chr(&obj,2,1,'b');
	lcd_out_num(&obj,2,3,-500);
	lcd_cmd(&obj,LCD_SHIFT_RIGHT);
	
    while (1) 
    {
    }
}

