/*
 * robot.c
 *
 * Created: 2/16/2018 4:36:38 PM
 * Author : abdo
 */ 


#include <avr/io.h>
#include <stdio.h> //?
#define F_CPU 1000000UL
#include "DISTANCE_DETECTOR.h"
#include <util/delay.h>
#include "lcd.h"

int main(void)
{   
	uint16_t ultra_scoic_time = 0;
	

   DDRD = 0;
   DDRD |=(1<<5);
   
     //echo
   
    while (1) 
    {
	start(3);  //trig	
	ultra_scoic_time  = MEASURE_IN_CM();
	TCCR1B = 0;	
	_delay_ms(500);
	}
	//lcd
		init();
		display_int(ultra_scoic_time );
	return 0 ;
}


