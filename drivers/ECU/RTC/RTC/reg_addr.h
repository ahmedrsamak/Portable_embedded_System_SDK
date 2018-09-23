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
	TWBR = 0x20,
	TWSR,
	TWAR,
	TWDR,
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
	TWCR=0x56,
}port_base;




#endif /* REG_ADDR_H_ */