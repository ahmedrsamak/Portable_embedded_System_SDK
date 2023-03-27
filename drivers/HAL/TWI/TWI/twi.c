/*
 * i2c.c
 *
 * Created: 9/12/2018 10:03:38 PM
 *  Author: Eng/Hossam Adel
 *  Modified by Ahmed Samak
 */ 
#include "twi.h"
void TWI_Init(u16 freq,u8 slave_addr)
{
    // freq -> Enter freq with KHz for example 400 is 400KHz
    TWBR=(F_CPU/(2000L*freq)-8);
	TWSR=0x00;
    // Two Wire Bus address my address if any master device want to call me: use addr (used in case this MC is a slave device)
    // General Call Recognition: Off
   TWAR=slave_addr<<1; // my address masking with first bit 	
    TWCR=(1<<2); //enable TWI
}

void TWI_Start(void)
{
    /* Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
   TWCR = (1 << 7) | (1 << 5) | (1 << 2);
    
    // Wait for TWINT flag set in TWCR Register (start bit is send successfully) 
    while (!(TWCR & (1 << 7)));
}

void TWI_Stop(void)
{
    /* Clear the TWINT flag before sending the stop bit TWINT=1
	 * Enable TWI Module TWEN=1 
	 * send the stop bit by TWSTO=1
	 */
    TWCR = (1 << 7) | (1 << 2) | (1 << 4);
}

void TWI_Write(u8 data)
{
    // Put data On TWI Register
    TWDR = data;
    /* Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << 7) | (1 << 2);
    // Wait for TWINT flag set in TWCR Register(data is send successfully) 
    while (!(TWCR & (1 << 7)));
}

u8 TWI_Read_With_ACK(void)
{
	/* Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 * enable sending ACK TWEA=1
	 */ 
    TWCR = (1 << 7) | (1 << 2) | (1<<6);
    // Wait for TWINT flag set in TWCR Register (data received successfully) 
    while (!(TWCR & (1 << 7)));
    // Read Data
    return TWDR;
}

u8 TWI_Read_With_NACK(void)
{
	/* Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 * disable sending ACK TWEA=0
	 */
    TWCR = (1 << 7) | (1 << 2);
	TWCR &=~(1<<6);
    // Wait for TWINT flag set in TWCR Register (data received successfully) 
    while (!(TWCR & (1 << 7)));
    // Read Data
    return TWDR;
}

u8 TWI_Get_Status(void)
{
    u8 status;
    status = TWSR & 0xF8; //masking to eliminate first 3 bits 
    return status;
}
