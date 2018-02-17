/*
 * DISTANCE_DETECTOR.h
 *
 * Created: 1/30/2018 11:15:45 AM
 *  Author: HMS
 */ 


#ifndef DISTANCE_DETECTOR_H_
#define DISTANCE_DETECTOR_H_
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define ECHO1 PD5


#define ECHO2 PD6
#define TRIG2 PB2

#define ECHO1_reg DDRB
#define TRIG1_reg DDRD

#define ECHO1_port PORTB
#define TRIG1_port PORTD

#define ECHO2_reg DDRD
#define TRIG2_reg DDRD

#define ECHO2_port PORTD
#define TRIG2_port PORTD

 uint16_t MEASURE_IN_SEC();
 uint16_t MEASURE_IN_CM();
void start( uint8_t trig);
void TRIG_SIGNAL(  );



#endif /* DISTANCE_DETECTOR_H_ */