/*
 * 7-SEGMANT.c
 *
 * Created: 9/23/2018 11:19:56 AM
 * Author : ahmed
 */
#include "ecu_7segm.h"
#include <util/delay.h> 
config_7segm obj;
int main(void)
{
	obj.pins[0]=0;
	obj.pins[1]=1;
	obj.pins[2]=2;
	obj.pins[3]=3;
	obj.port=portb;
	
   sev_segm_init(&obj);
   for (int i=0;i<=9;i++)
   {
	   sev_segm_out(&obj,i);
	   _delay_ms(500);
   }
    while (1) 
    {
    }
}

