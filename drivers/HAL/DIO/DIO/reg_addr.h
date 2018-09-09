/*
 * reg_addr.h
 *
 * Created: 9/8/2018 10:11:39 PM
 *  Author: ahmed
 */ 


#ifndef REG_ADDR_H_
#define REG_ADDR_H_
typedef enum
{
	INVALID_MIN_INDEX=0x2F,
	PIND = 0X30,
	DDRD,
	PORTD,
	PINC,
	DDRC,
	PORTC,
	PINB,
	DDRB,
	PORTB,
	PINA,
	DDRA,
	PORTA,
	INVALID_MAX_INDEX,
}port_base;




#endif /* REG_ADDR_H_ */