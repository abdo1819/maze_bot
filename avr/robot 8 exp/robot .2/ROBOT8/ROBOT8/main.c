/*
 * ULTRA_SONIC.c
 *
 * Created: 1/30/2018 7:45:32 AM
 * Author : HMS
 */ 

#include <avr/io.h>
 
#include <stdio.h>
#define F_CPU 1000000UL
#include "DISTANCE_DETECTOR.h"
#include <util/delay.h>
#include "lcd.h"

int main(void)
{     
	  uint16_t RIGHT=0;
	  uint16_t LEFT=0;
	DDRD=0;
	PORTD|=1<<PD3;
	
	

    while (1) 
    {

		
		start(PORTD1);
		LEFT=MEASURE_IN_CM();
		  

	DDRC |= (1<<3)|(1<<4);
	
	if (LEFT >200 & LEFT<700 )
	{
		PORTC |= (1<<3)|(1<<4);
	}
	if(LEFT >700)
	{
		PORTC &= ~(1<<3) & ~(1<<4);
	}

		_delay_ms(50);		 
		 init();
		 display_int(LEFT);
		 _delay_ms(10);
    }

}
