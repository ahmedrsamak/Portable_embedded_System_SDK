/*
 * RTC.c
 *
 * Created: 9/23/2018 1:00:30 AM
 * Author : ahmed
 */ 

#include "ecu_rtc.h"
#include "LCD/ecu_lcd.h"
config_lcd_pin LCD1;
int main(void)
{
	u8 x[3];
	LCD1.ctrl_port=PORTA;
	LCD1.data_port=PORTB;
	LCD1.RS_pin=7;
	LCD1.E_pin=6;
	LCD1.data_pin[0]=4;
	LCD1.data_pin[1]=5;
	LCD1.data_pin[2]=6;
	LCD1.data_pin[3]=7;
	lcd_init(&LCD1);
  rtc_init();
  rtc_set_time(0x02,0xA,0x01);
  _delay_ms(100);
  rtc_read_time(&x[0],&x[1],&x[2]);
  lcd_out_str(&LCD1,1,1,"Time is: ");
  lcd_out_num(&LCD1,2,2,x[0]);
  lcd_out_num(&LCD1,2,5,x[1]);
  lcd_out_num(&LCD1,2,9,x[2]);
    while (1) 
    {
    }
}

