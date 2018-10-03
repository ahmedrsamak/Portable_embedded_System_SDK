/*
 * TIMER.c
 *
 * Created: 9/29/2018 10:37:37 PM
 * Author : ahmed
 */
#include "hal_timer0.h"

//#include "reg_addr.h"
//#include "common.h"
//#include <avr/interrupt.h>
#include "hal_dio.o"
int x;
void test()
{
	
}
int main(void)
{
    timer0_call_back(&test);
	timer0_start(NO_PRESCALER,32);
    while (1) 
    {
	x =  timer0_read();
    }
}

