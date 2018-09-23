/*
 * rtc.c
 *
 * Created: 9/23/2018 1:06:46 AM
 *  Author: ahmed
 */ 
#include "rtc.h"
#include <util/delay.h>
void rtc_init()
{
	TWI_Init(100,0);
	TWI_Start();
	TWI_Write(0xD0); //chip address D with write bit 0
	TWI_Write(0x07); // control reg
	TWI_Stop();
	_delay_us(100);
}
void rtc_set_time(u8 hour,u8 minute,u8 second)
{
	TWI_Start();
	TWI_Write(0xD0);
	TWI_Write(0x00); // starting address for seconds
	TWI_Write(second);
	TWI_Write(minute);
	TWI_Write(hour);
	TWI_Stop();
}
void rtc_set_date(u8 year,u8 month,u8 day)
{
	TWI_Start();
	TWI_Write(0xD0);
	TWI_Write(0x04); // starting address for seconds
	TWI_Write(day);
	TWI_Write(month);
	TWI_Write(year);
	TWI_Stop();
}
void rtc_read_time(u8 * hour,u8 * minute,u8 * second)
{
	TWI_Start();
	TWI_Write(0xD0);
	TWI_Write(0x00);
	TWI_Stop();
	TWI_Start();
	TWI_Write(0xD1);
	*second=TWI_Read_With_ACK();
	*minute=TWI_Read_With_ACK();
	*hour=TWI_Read_With_NACK();
	TWI_Stop();
}
void rtc_read_date(u8 * year,u8 * month,u8 * day)
{
	TWI_Start();
	TWI_Write(0xD0);
	TWI_Write(0x04);
	TWI_Stop();
	TWI_Start();
	TWI_Write(0xD1);
	*day=TWI_Read_With_ACK();
	*month=TWI_Read_With_ACK();
	*year=TWI_Read_With_NACK();
	TWI_Stop();	
}
