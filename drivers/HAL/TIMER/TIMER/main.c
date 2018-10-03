/*
 * TIMER.c
 *
 * Created: 9/29/2018 10:37:37 PM
 * Author : ahmed
 */
#include "hal_timer0.h"
int x;
void test()
{
	DDRD=0xFF;	
}
int main(void)
{
    timer0_call_back(&test);
	timer0_start(NO_PRESCALER,0);
    while (1) 
    {
	x =  timer0_read();
    }
}

