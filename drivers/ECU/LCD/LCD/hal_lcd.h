/*
 * hal_lcd.h
 *
 * Created: 9/10/2018 2:11:11 AM
 *  Author: ahmed
 */ 


#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include "DIO/hal_dio.h"
#include <util/delay.h>
#define bit_mode 4
typedef enum
{
 test=1,
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
void lcd_out(config_lcd_pin * obj,u8 y,u8 x,char * string);
void lcd_cmd(config_lcd_pin * obj,enum_cmd cmd);


#endif /* HAL_LCD_H_ */