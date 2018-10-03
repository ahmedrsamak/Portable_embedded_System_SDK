/*
 * hal_timer.c
 *
 * Created: 9/30/2018 12:35:29 AM
 *  Author: ahmed
 */ 
#include "hal_timer0.h"

static void (*cb)(void);


ISR(TIMER0_COMP_vect)
{
	cb();
}
ISR(TIMER0_OVF_vect)
{
	cb();
}
void timer0_start(PRESCALER_SELC prescaller,u8 comp_value)
{
	TCCR0|= 0x08;
	TIMSK|= 0x03;
	OCR0  = comp_value;
	TCNT0 = 0;
	sei();
	TCCR0|= prescaller;
}

void timer0_update(u8 comp)
{
	OCR0 = comp;
	TCNT0=0;
}
u8 timer0_read()
{
	return TCNT0;
}
void timer0_stop()
{
	TCCR0 = 0x00;
	TIMSK = 0x00;
	OCR0  = 0x00;
	TCNT0 = 0x00;
}


void timer0_call_back(void (*ucb)(void))
{
	cb=ucb;
}