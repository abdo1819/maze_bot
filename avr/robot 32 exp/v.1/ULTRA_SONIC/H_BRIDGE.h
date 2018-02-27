/*
 * H_BRIDGE.h
 *
 * Created: 2/11/2018 12:59:11 PM
 *  Author: modern
 */ 


#ifndef H_BRIDGE_H_
#define H_BRIDGE_H_
#include "LCD.h"
#define  ENA1_R DDRB
#define  ENA2_R DDRD

#define  IN1_A_R DDRB
#define  IN2_A_R DDRB

#define  IN1_B_R DDRD
#define  IN2_B_R DDRD



#define  ENA1_PORT PORTB
#define  ENA2_PORT PORTD

#define  IN1_A_PORT PORTB
#define  IN2_A_PORT PORTB

#define  IN1_B_PORT PORTD
#define  IN2_B_PORT PORTD

void MOVE_FORWARD_1(uint8_t D);
void MOVE_BACKWARD_1(uint8_t D);
void MOVE_FORWARD_2(uint8_t D);
void MOVE_BACKWARD_1(uint8_t D);
void TURN_BY_A(uint8_t D);
void TURN_BY_B(uint8_t D);
void MOVE_FORWARD_ALL(uint8_t D);
void MOVE_BACKWARD_ALL(uint8_t D);
void Turn_OFF1();
void Turn_OFF2();

void START_MOTORs(uint8_t A1, uint8_t A2, uint8_t B1, uint8_t B2);

#endif /* H_BRIDGE_H_ */