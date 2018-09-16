/*
 * External_EEPROM.c
 *
 * Created: 9/13/2018 10:17:23 AM
 * Author : ahmed
 */ 
#include "LCD/hal_lcd.h"
#include "TWI/hal_twi.h"
#include <stdlib.h>
config_lcd_pin LCD1;
char _data[7];
int main(void)
{
	itoa(16,_data,10);
	//char _data;
	//_data=int_to_str(15,2);
	LCD1.ctrl_port=PORTB;
	LCD1.data_port=PORTB;
	LCD1.RS_pin=2;
	LCD1.E_pin=3;
	LCD1.data_pin[0]=4;
	LCD1.data_pin[1]=5;
	LCD1.data_pin[2]=6;
	LCD1.data_pin[3]=7;
	
   lcd_init(&LCD1);
   TWI_Init(100,0x01);
   lcd_cmd(&LCD1,LCD_ON_CURSOR_OFF);
   lcd_out(&LCD1,1,1,"Start");
   _delay_ms(100);
   lcd_out(&LCD1,2,1,_data);
   TWI_Start();
   TWI_Write(0b10100000);
   _delay_ms(500);
   TWI_Write(0xFF);
   _delay_ms(500);
   TWI_Write(0xFE);
   _delay_ms(500);
   TWI_Stop();
   _delay_ms(1000);
   TWI_Start();
   TWI_Write(0b10100001);
  // data=TWI_Read_With_NACK();
   TWI_Stop();
  
    while (1) 
    {
    }
}

