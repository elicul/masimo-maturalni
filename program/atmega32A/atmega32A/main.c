/*
 * atmega32A.c
 *
 * Created: 2.3.2019. 15:12:08
 * Author : elicul
 */ 

#include <avr/io.h>
//#include <util/delay.h>

int main(void)
{
    DDRD = 0xFF;
    while(1)
    {
	    PORTD = 0xFF;
	    //_delay_ms(500);
	    //PORTD = 0x00;
	    //_delay_ms(500);
    }
}

