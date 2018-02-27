
/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sesores).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    ---------------------
 * | HC-SC04 | Arduino |    | 3 pins  | Arduino |
 * ---------------------    ---------------------
 * |   Vcc   |   5V    |    |   Vcc   |   5V    |
 * |   Trig  |   12    | OR |   SIG   |   13    |
 * |   Echo  |   13    |    |   Gnd   |   GND   |
 * |   Gnd   |   GND   |    ---------------------
 * ---------------------
 * Note: You need not obligatorily use the pins defined above
*/
#include <Ultrasonic.h>

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */

const int special = 10 ; 


Ultrasonic ultrasonic1(2, 3);
Ultrasonic ultrasonic2(4, 5);
Ultrasonic ultrasonic3(6, 7);

float ultra_right = 0;
float ultra_left = 0; 
float ultra_front = 0;

bool front = 0;
bool right = 0;
bool left = 0;

int c = 0;

bool turn = 0;
#define right_maze 0
#define left_maze 1

bool pair_high = 0;


void read(){
  ultra_front = ultrasonic1.distanceRead();
  ultra_right = ultrasonic2.distanceRead();
  ultra_left = ultrasonic3.distanceRead();

  if (ultra_front > special ){
    front = 1;  
  }
  else{
    front = 0;
  }

   if (ultra_right > special ){
    right = 1;
  }
  else{
      right = 0;
  }

   if (ultra_left > special ){
    left = 1;
  }
  else {
      left =0;
  }

  if (front+right+left >= 2){
    pair_high = 1; 
  }
  else{
    pair_high = 0;
  }
}

void go_forward(){
  //two motors high;
  digitalWrite(8,1);
  digitalWrite(9,1);
}

void turn_right(){
  //turn right
  digitalWrite(9,1);
  digitalWrite(8,0);
}

void turn_left(){
  //right
  digitalWrite(8,1);
  digitalWrite(9,0);
}

void setup() {
  Serial.begin(9600);
  Serial.println("1\t2\t3");

  pinMode(8,1);      //led
  pinMode(9,1);          //led
  pinMode(10,1);

  
}

void loop() {

  read();  //read three ultra and 

  Serial.print(ultra_front);
  Serial.print("\t");
  Serial.print(ultra_right);
  Serial.print("\t");
  Serial.println(ultra_left);



  if (c>0 && pair_high){   //enter after first check of maze type
    switch(turn){
      
      case right_maze:
      if ( left & right )
      {
        turn_left();
      }
      else if (left & front)
      {
        turn_left();
      }
      break;
      
      case left_maze:
      if ( right & left )
      {
        turn_right();
      }
      else if (right & front)
      {
        turn_right();
      }
      break;
    }
  }
  
if (~pair_high)
  {
  
  if (front){
    go_forward();
  }

  else if (right){
    turn_right();   
  if (c==0){    //check maze default turn
    turn = right_maze;
    c++;
  }
    
  }

  else if(left){
    turn_left();
  if (c==0){  //check maze default turn
    turn = left_maze;
    c++;
  }
  
  }
  
  }

}
