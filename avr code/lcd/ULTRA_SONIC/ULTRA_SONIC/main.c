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
#include "LCD.h"
int main(void)
{     uint16_t RIGHT=0;
	  uint16_t LEFT=0;
	DDRD=0;
	PORTD|=1<<PD3;
	char buff[50]="010";
	
	
	LCD_START();

    while (1) 
    {
		
		start(PD4);
		LCD_START();//must reset LCD because common pins with LCD PORT   
		LEFT=MEASURE_IN_CM();
		LCD_GoTo_XY(1,0);
		sprintf(buff,"%u",LEFT);
		_delay_ms(50);
		DISP_WORD(buff);
		 _delay_ms(500);
		  LCD_ClearScreen();
		  _delay_ms(100);
		 //READ THE OTHER DISTANCE
		 start(PD6);
		 LCD_START();//must reset LCD because common with LCD PORT   
		 RIGHT=MEASURE_IN_CM();
		 sprintf(buff,"%u",RIGHT);
		 _delay_ms(50);
		 DISP_WORD(buff);
		 
		 _delay_ms(500);
		 LCD_ClearScreen();
		 _delay_ms(100); 
		 
		 
		 if (LEFT<RIGHT)
		 {
			 DDRB|=(1<<PB1);
			  PORTB^=(1<<PB1);
			    
		
		 }
		  
    }

}

 
