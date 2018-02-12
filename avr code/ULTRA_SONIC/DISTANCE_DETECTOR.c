/*
 * DISTANCE_DETECTOR.c
 *
 * Created: 1/30/2018 11:14:51 AM
 *  Author: HMS
 */ 

#include "DISTANCE_DETECTOR.h"
#include "LCD.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
volatile int16_t secs=0;
volatile uint16_t over_flow=0;
uint8_t trig_val =TRIG1;


volatile  char flag=1;
  char buff[50];
void start( uint8_t trig)
{  //init trig position , interrupt type and interrupt pin
	 
	
	// determine the interrupt pin that will be used by knowing which trig will be send
	if (trig==6)//case of int2
	{
		TCCR1B=0;

		
		MCUCSR|=(1<<ISC2);//rising edge
		GICR|=(1<<INT2);//enable int2
		DDRD|=(1<<trig);
		trig_val=trig;//pass trig to trig signal function
		flag=1;
	}
	else
	 {
		 	TCCR1B=0;

		//case of int1
		 MCUCR|=(1<<ISC10);
		 GICR|=(1<<INT1);
		 DDRD|=(1<<trig);
		 trig_val=trig;//pass trig to trig signal function
		 flag=1;
	
	}
	sei();//enable global interrupt
}


 uint16_t MEASURE_IN_CM()
{
	TRIG_SIGNAL();
	//timer 1 no prescale lowest time =1/million=.001msec and max =1/million*2^16=65ms
	//lowest time from hc sr04 =150 u sec=.15 m sec ****data sheet****
	//max time from hc sr04 =25 m sec or 18 m sec(will not reach it)****data sheet****
	// no obstacle time= 38 m sec
 while((flag==0)&&(secs==0)){
	 
	 if (over_flow>=1)
	 { 
		  
		 return 0;//in case of wrong connection or any problems (TIMER VALUE WIll NOT OVER FLOW ) ZERO RETURN IN CASE OF OVER FLOW
		 }
		 
	 }
	 _delay_ms(50);
	TCCR1B=0;
	DDRD&=~(1<<trig_val);

 	return secs;//CONVERSION MISSED XD
}
void TRIG_SIGNAL( )
{
	//send trig pulse
	PORTD|=(1<<trig_val);
	_delay_us(10);
	PORTD&=~(1<<trig_val);
	_delay_us(750);
		TCCR1B=0;

}
ISR(INT1_vect)
{
	if (flag==1){
	TCCR1B|=(1<<CS10);
	TIMSK|=(1<<TOIE1);
	
	TCNT1=0;
	flag=0;
	secs=0;
	}
	else
	 {   secs=TCNT1;
		 TCCR1B=0;
		  
		 flag=1;
	     over_flow=0;
		TCNT1=0;
		TCCR1B=0;
	}
}
ISR(INT2_vect)
{
	if (flag==1){
		TCCR1B|=(1<<CS10);
		TIMSK|=(1<<TOIE1);
		
		TCNT1=0;
		flag=0;
		secs=0;
		MCUCSR&=~(1<<ISC2);
	}
	else
	{   secs=TCNT1;
		TCCR1B=0;
		 
		flag=1;
		over_flow=0;
		TCNT1=0;
		 TCCR1B=0;
		
	}
}
ISR(TIMER1_OVF_vect)
{
	over_flow=over_flow+1;
	TCNT1=0;
	TCCR1B|=(1<<CS10);
	DDRA=0xff;
	PORTA=~PORTA;//over flow test
 }