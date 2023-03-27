/*
 * 7segm.c
 *
 * Created: 9/23/2018 11:25:06 AM
 *  Author: ahmed
 */ 
#include "7segm.h"
void sev_segm_init(config_7segm * obj)
{
	for (int i=0;i<4;i++)
	{
		dio_set_pin_dir(obj->port,obj->pins[i],OUTPUT);
	}
}
void sev_segm_out(config_7segm * obj , u8 num)
{
	for (int i=0;i<4;i++)
	{
		dio_write_pin(obj->port,obj->pins[i],((1<<i) & num)>>i); // 0111 // 1 //  
	}
}