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
	reg(DDRD)=0xff;//~reg(DDRD);
}
int main(void)
{
	
   timer0_start(NO_PRESCALER,8);
 //  timer0_call_back(&test);
    while (1) 
    {
//	x =  timer0_read();
    }
}

