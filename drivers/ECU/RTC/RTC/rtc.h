/*
 * rtc.h
 *
 * Created: 9/23/2018 1:06:57 AM
 *  Author: ahmed
 */ 


#ifndef RTC_H_
#define RTC_H_
#include "TWI/hal_twi.h"
void rtc_init();
void rtc_set_time(u8 hour,u8 minute,u8 second);
void rtc_set_date(u8 year,u8 month,u8 day);
void rtc_read_time(u8 * hour,u8 * minute,u8 * second);
void rtc_read_date(u8 * year,u8 * month,u8 * day);



#endif /* RTC_H_ */