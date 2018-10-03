/*
 * DIO.c
 *
 * Created: 9/8/2018 9:48:29 PM
 * Author : ahmed
 */ 


#include "hal_dio.h"
int main(void)
{
   dio_set_port_dir(porta,OUTPUT);
   dio_set_port_dir(portb,INPUT);
   dio_set_pin_dir(portc,3,OUTPUT);
   dio_set_pin_dir(portc,4,INPUT);
   dio_write_port(porta,HIGH);
   dio_write_port(porta,LOW);
   dio_write_pin(portc,3,HIGH);
   dio_write_pin(portc,3,LOW);
   dio_read_port(portb);
   dio_read_pin(portc,4);
    while (1) 
    {
    }
}

