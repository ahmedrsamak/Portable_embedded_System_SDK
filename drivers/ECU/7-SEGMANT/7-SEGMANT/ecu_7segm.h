/*
 * ecu_7segm.h
 *
 * Created: 9/23/2018 11:25:17 AM
 *  Author: ahmed
 */ 


#ifndef ECU_7SEGM_H_
#define ECU_7SEGM_H_
#include "DIO/hal_dio.h"
typedef struct
{
 u8 port;
 u8 pins[4];
}config_7segm;
void sev_segm_init(config_7segm * obj);
void sev_segm_out(config_7segm * obj , u8 num);


#endif /* ECU_7SEGM_H_ */