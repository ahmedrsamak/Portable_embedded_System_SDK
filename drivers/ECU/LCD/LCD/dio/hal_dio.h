/*
 * hal_dio.h
 *
 * Created: 9/8/2018 9:49:26 PM
 *  Author: ahmed
 */ 


#ifndef HAL_DIO_H_
#define HAL_DIO_H_
#include "../dio/common.h"
#include "../dio/reg_addr.h"
typedef enum
{
OUTPUT=0x01,
INPUT =0X00,
}dir;
typedef enum
{
HIGH=0X01,
LOW =0X00,
}state;

void dio_set_port_dir(port_base port,dir mode);
void dio_set_pin_dir(port_base port,u8 pin,dir mode);
void dio_write_port(port_base port,state mode);
void dio_write_pin(port_base port,u8 pin,state mode);
u8 dio_read_port(port_base port);
u8 dio_read_pin(port_base port,u8 pin);
#endif /* HAL_DIO_H_ */