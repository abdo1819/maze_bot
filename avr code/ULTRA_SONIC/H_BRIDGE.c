#include "H_BRIDGE.h"
#include "LCD.h"
uint8_t A_1,   A_2, B_1,  B_2, ENA_1, ENA_2;
void START_MOTORs(uint8_t A1, uint8_t A2, uint8_t B1, uint8_t B2)
{
	ENA1_R|=(1<<PB3);
	ENA2_R|=(1<<PD7);
	IN1_A_R|=(1<<A1);
	IN2_A_R|=(1<<A2);
	IN1_B_R|=(1<<B1);
	IN2_B_R|=(1<<B2);
	TCCR0|=(1<<COM01)|(1<<WGM00)|(1<<CS00) ;//set as PWM on oc0 with no pre-scaling
	TCCR2|=(1<<COM21)|(1<<WGM20)|(1<<CS20) ;//set as PWM on oc0 with no pre-scaling
	
	A_1=A1;
	A_2=A2;
	B_1=B1;
	B_2=B2;
/*	ENA_1=ENA1;
	ENA_2=ENA2;*/
}
void MOVE_FORWARD_1(uint8_t D)
{
	IN1_A_PORT|=(1<<A_1);
	IN2_A_PORT&=~(1<<A_2);
	
	OCR0=D;
	
}
void MOVE_BACKWARD_1(uint8_t D)
{
	IN1_A_PORT&=~(1<<A_1);
	IN2_A_PORT|=(1<<A_2);
	
	OCR0=D;
	
}
void MOVE_FORWARD_2(uint8_t D)
{
	IN1_B_PORT|=(1<<B_1);
	IN2_B_PORT&=~(1<<B_2);
	
	OCR2=D;
	
}
void MOVE_BACKWARD_2(uint8_t D)
{
	IN1_B_PORT&=~(1<<B_1);
	IN2_B_PORT|=(1<<B_2);
	
	OCR2=D;
	
}

void MOVE_FORWARD_ALL(uint8_t D)
{
	MOVE_FORWARD_1(D);
	MOVE_FORWARD_2(D);
}
void MOVE_BACKWARD_ALL(uint8_t D)
{
	MOVE_BACKWARD_1(D);
	MOVE_BACKWARD_2(D);
  }
 void Turn_OFF1()
  {
	IN1_A_PORT&=~(1<<A_1);
	IN1_A_PORT&=~(1<<A_1);
	OCR0=0;
	OCR2=0;
  }
  
  void Turn_OFF2()
  {
	  IN2_A_PORT&=~(1<<A_2);
	  IN2_A_PORT&=~(1<<A_2);
	  OCR0=0;
	  OCR2=0;
  }
  void TURN_BY_A(uint8_t D)
  {
	  MOVE_FORWARD_1(D);
	  MOVE_FORWARD_2(0);

  }
  void TURN_BY_B(uint8_t D)
  {
	  MOVE_FORWARD_1(0);
	  MOVE_FORWARD_2(D);

  }
