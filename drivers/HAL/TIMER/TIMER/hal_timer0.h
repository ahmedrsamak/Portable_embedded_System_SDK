/*
 * hal_timer.h
 *
 * Created: 9/30/2018 12:35:43 AM
 *  Author: ahmed
 */ 


#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_
#include "common.h"

//#include "reg_addr.h"
typedef enum
{
	TMR_STOP,
	NO_PRESCALER,
	DIV_8,
	DIV_64,
	DIV_256,
	DIV_1024,
	EXT_CLK_FALLING_EDGE,
	EXT_CLK_RISING_EDGE,
}PRESCALER_SELC;

void timer0_start(PRESCALER_SELC prescaller,u8 comp_value);
void timer0_update(u8 comp);
u8 timer0_read();
void timer0_stop();
void timer0_call_back(void (*cb)(void));



#endif /* HAL_TIMER_H_ */