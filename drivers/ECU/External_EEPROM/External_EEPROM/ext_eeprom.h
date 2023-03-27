/*
 * ext_eeprom.h
 *
 * Created: 9/19/2018 12:35:09 AM
 *  Author: ahmed samak
 * this driver for 24c08N
 */ 
#include "TWI/twi.h"

#ifndef EXT_EEPROM_H_
#define EXT_EEPROM_H_
/*
* void ext_eeprom_init(u8 freq)
* set freq of the EEPROM get from data sheet for 24c08N is 100KHz
*/
void ext_eeprom_init(u8 freq);
/*
* void ext_eeprom_write(u8 chip_addr,u16 block_addr,u8 data)
* write byte to EEPROM
* chip address set to 000 or 100 for 24c08N 
* chip address set to 000 to 111 for 24c01N and 24c02N
* chip address set to 000 to 110 for 24c04N
* chip address set to 000        for 24c16N
* block_addr is the address for data to write
* data is the the char to be written to the specific address
*/
void ext_eeprom_write(u8 chip_addr,u16 block_addr,u8 data);
/*
* u8   ext_eeprom_read(u8 chip_addr,u16 block_addr)
* write byte to EEPROM
* block_addr is the address for data to read from
* return the data
*/
u8 ext_eeprom_read(u8 chip_addr,u16 block_addr);


#endif /* EXT_EEPROM_H_ */