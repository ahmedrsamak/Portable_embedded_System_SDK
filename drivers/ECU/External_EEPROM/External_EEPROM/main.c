/*
 * External_EEPROM.c
 *
 * Created: 9/13/2018 10:17:23 AM
 * Author : ahmed samak
 */ 
#include "LCD/hal_lcd.h"
#include "ext_eeprom.h"

u8 y;
int x=0;
config_lcd_pin LCD1;
int main(void)
{
	dio_set_port_dir(PORTA,OUTPUT);
	LCD1.ctrl_port=PORTB;
	LCD1.data_port=PORTB;
	LCD1.RS_pin=2;
	LCD1.E_pin=3;
	LCD1.data_pin[0]=4;
	LCD1.data_pin[1]=5;
	LCD1.data_pin[2]=6;
	LCD1.data_pin[3]=7;
    lcd_init(&LCD1);
	
    ext_eeprom_init(100);
	ext_eeprom_write(0,01,57);
	_delay_ms(10);
	y=ext_eeprom_read(0,01);
   lcd_cmd(&LCD1,LCD_CLEAR);
   lcd_out_str(&LCD1,1,1,"data is: ");
   lcd_out_num(&LCD1,2,1,(u8)y);
    while (1) 
    {
    }
}

