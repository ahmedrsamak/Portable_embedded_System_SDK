/*
 * hal_lcd.h
 *
 * Created: 9/10/2018 2:11:11 AM
 *  Author: ahmed
 */ 


#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include "../LCD/DIO/hal_dio.h"
#include <util/delay.h>
#define bit_mode 4
typedef enum
{
 LCD_CLEAR=0x01,	
 LCD_SHIFT_RIGHT=0x1C,
 LCD_SHIFT_LEFT= 0x18,
 LCD_OFF_CURSOR_OFF=0x08,
 LCD_OFF_CURSOR_ON =0x0A ,
 LCD_ON_CURSOR_OFF=0x0C,
 LCD_ON_CURSOR_BLINKING=0x0F,
  
}enum_cmd;
typedef struct
{
	u8 data_port;
	u8 ctrl_port;
	u8 data_pin[bit_mode];
	u8 RS_pin;
	u8 E_pin;
}config_lcd_pin;

void lcd_init(config_lcd_pin * obj);
void lcd_out_chr(config_lcd_pin * obj,u8 y,u8 x,char  chr);
void lcd_out_str(config_lcd_pin * obj,u8 y,u8 x,char * string);
void lcd_out_num(config_lcd_pin * obj,u8 y,u8 x,s16 num);
void lcd_cmd(config_lcd_pin * obj,enum_cmd cmd);


#endif /* HAL_LCD_H_ */