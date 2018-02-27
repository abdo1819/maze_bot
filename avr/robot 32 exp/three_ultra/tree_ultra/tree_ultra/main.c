/*
 * tree_ultra.c
 *
 * Created: 2/24/2018 8:24:17 PM
 * Author : abdo
 */ 

#include <avr/io.h>

#include "lcd.h"
#include "DISTANCE_DETECTOR.h"
#include <util/delay.h>

void delay_ms( int ms )
{
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

int main(void)
{
    /* Replace with your application code */
    DDRB |= (1<<0);
	while (1) 
    {
		
		start(4);
		int dis = MEASURE_IN_MM();
		PORTB^=(1<<0);
		delay_ms(dis);
	
	    }
}

