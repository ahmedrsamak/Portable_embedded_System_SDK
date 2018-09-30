/*
 * hal_timer.c
 *
 * Created: 9/30/2018 12:35:29 AM
 *  Author: ahmed
 */ 
#include "hal_timer0.h"
#include <avr/interrupt.h>

/*
static void (*cb)(void);

ISR(TIMER0_COMP_vect)
{
	cb();
}
ISR(TIMER0_OVF_vect)
{
	cb();
}*/
void timer0_start(PRESCALER_SELC prescaller,u8 comp_value)
{
	reg(TCCR0)|= 0x08;
	reg(TIMSK)|= 0x03;
	reg(OCR0)  = 32;
	reg(TCNT0) = 0;
	reg(TCCR0)|= 0;
	//sei();
}
/*
void timer0_update(u8 comp)
{
	reg(OCR0) = comp;
	reg(TCNT0)=0;
}
u8 timer0_read()
{
	return reg(TCNT0);
}
void timer0_stop()
{
	reg(TCCR0) = 0x00;
	reg(TIMSK) = 0x00;
	reg(OCR0)  = 0x00;
	reg(TCNT0) = 0x00;
}*/

/*
void timer0_call_back(void (*ucb)(void))
{
	cb=ucb;
}*/