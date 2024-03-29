/*
 * common.h
 *
 * Created: 9/8/2018 9:53:08 PM
 *  Author: ahmed
 */ 


#ifndef COMMON_H_
#define COMMON_H_
//#define SetBit(reg,pin) reg|=(1<<pin)
//#define ClrBit(reg,pin) reg&=~(1<<pin)
//#define ToggleBit(reg,pin) reg^=(1<<pin)
#define TRUE 1
#define  FALSE 0
#define NULL ((void *)0)
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed short int s16;
typedef signed long int s32;

#endif /* COMMON_H_ */