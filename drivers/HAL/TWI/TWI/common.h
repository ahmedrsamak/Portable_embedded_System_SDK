/*
 * common.h
 *
 * Created: 9/8/2018 9:53:08 PM
 *  Author: ahmed
 */ 


#ifndef COMMON_H_
#define COMMON_H_
#define F_CPU 8000000
//#define SetBit(reg,pin) reg|=(1<<pin)
//#define ClrBit(reg,pin) reg&=~(1<<pin)
//#define ToggleBit(reg,pin) reg^=(1<<pin)
#define TRUE 1
#define  FALSE 0
#define NULL ((void *)0)

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

#endif /* COMMON_H_ */