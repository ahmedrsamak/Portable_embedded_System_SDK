/*
 * hal_lcd.c
 *
 * Created: 9/10/2018 2:11:27 AM
 *  Author: ahmed
 */ 
#include "hal_lcd.h"
static void send_4bit_data(u8 data)
{
   static short int i;
 for (i=0;i<bit_mode;i++)
 {
	 dio_write_pin()
	 
 }	
}
void lcd_init(config_lcd_pin * obj)
{
	static short int i;
	for (i=0;i<bit_mode;i++)
	{
		dio_set_pin_dir(obj->port,obj->data_pin[i],OUTPUT);	
	}

 
 
}
void lcd_out(u8 y,u8 x,u8 * string);
void lcd_cmd(enum_cmd cmd);
