/*
 * ext_eeprom.c
 *
 * Created: 9/19/2018 12:34:48 AM
 *  Author: hossam adel
 */ 
#include "ext_eeprom.h"
void ext_eeprom_init(u8 freq)
{
	TWI_Init(freq,0x01); //init eeprom with its frequency and microcontroller slave address 0x01 is not used for eeprom
}
void ext_eeprom_write(u8 chip_addr,u16 block_addr,u8 data)
{
	 TWI_Start(); // send start bit
	 TWI_Write(0xA0 | (chip_addr<<1)); // write chip address with write bit is 0
	 TWI_Write(block_addr); //select block address to write data to it
	 TWI_Write(data); // data to write
	 TWI_Stop(); // send stop bit
}
u8 ext_eeprom_read(u8 chip_addr,u16 block_addr)
{
	u8 data;
	TWI_Start(); // send start bit
	TWI_Write(0xA0 | (chip_addr<<1)); // write chip address with write bit is 0
    TWI_Write(block_addr); // select block address to read from
	TWI_Start(); // send repeated start
    TWI_Write(0xA0 | (chip_addr<<1) | 1); // send chip addres again with read bit is 1
	data=TWI_Read_With_NACK(); // read the data and store in variable data
	TWI_Stop(); // send stop bit
	return data; // return data
}
