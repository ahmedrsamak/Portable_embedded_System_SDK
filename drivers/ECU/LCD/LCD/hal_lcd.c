/*
 * hal_lcd.c
 *
 * Created: 9/10/2018 2:11:27 AM
 *  Author: ahmed
 */ 
#include "hal_lcd.h"

static void send_4bit_data(u8 data,config_lcd_pin * obj)
{
   static short int i;
 for (i=0;i<bit_mode;i++)
 {
	 dio_write_pin(obj->data_port,obj->data_pin[i],(data>>(i+4))&0x01);
 }
 
 dio_write_pin(obj->ctrl_port,obj->E_pin,HIGH);	
 _delay_us(1);
 dio_write_pin(obj->ctrl_port,obj->E_pin,LOW);
 _delay_us(100);
 
 for (i=0;i<bit_mode;i++)
 {
	 dio_write_pin(obj->data_port,obj->data_pin[i],(data>>i)&0x01);
 }
 
 dio_write_pin(obj->ctrl_port,obj->E_pin,HIGH);
 _delay_us(1);
 dio_write_pin(obj->ctrl_port,obj->E_pin,LOW);
 _delay_us(100);
}

void lcd_init(config_lcd_pin * obj)
{
	u8 i;
	dio_set_pin_dir(obj->ctrl_port,obj->RS_pin,OUTPUT);
	dio_set_pin_dir(obj->ctrl_port,obj->E_pin,OUTPUT);
	for (i=0;i<bit_mode;i++)
	{
		dio_set_pin_dir(obj->data_port,obj->data_pin[i],OUTPUT);
	}
dio_write_pin(obj->ctrl_port,obj->RS_pin,LOW);
send_4bit_data(0x33,obj);
send_4bit_data(0x32,obj);
send_4bit_data(0x28,obj);
send_4bit_data(0x0E,obj);
send_4bit_data(0x01,obj);
_delay_ms(2);
send_4bit_data(0x06,obj);
}
void lcd_out(config_lcd_pin * obj,u8 y,u8 x,char * string)
{
	u8 i;
	dio_write_pin(obj->ctrl_port,obj->RS_pin,LOW);
	if (y==1)
	{
	 send_4bit_data(0x80,obj);
	}
	else
	{
	 send_4bit_data(0xC0,obj);
	}
	 for (i=0;i<(x-1);i++)
	 {
		 send_4bit_data(0x14,obj);
	 }
	 
	dio_write_pin(obj->ctrl_port,obj->RS_pin,HIGH);
	while(*string>0)
	{
	 send_4bit_data(*string++,obj);
	}	
}
void lcd_cmd(config_lcd_pin * obj,enum_cmd cmd);
