/*
 * DIO.c
 *
 * Created: 9/8/2018 9:48:29 PM
 * Author : ahmed
 */ 


#include "hal_dio.h"
int main(void)
{
   dio_set_port_dir(PORTA,OUTPUT);
   dio_set_port_dir(PORTB,INPUT);
   dio_set_pin_dir(PORTC,3,OUTPUT);
   dio_set_pin_dir(PORTC,4,INPUT);
   dio_write_port(PORTA,HIGH);
   dio_write_port(PORTA,LOW);
   dio_write_pin(PORTC,3,HIGH);
   dio_write_pin(PORTC,3,LOW);
   dio_read_port(PORTB);
   dio_read_pin(PORTC,4);
    while (1) 
    {
    }
}

