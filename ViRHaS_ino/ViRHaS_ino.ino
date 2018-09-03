#include "Encoder.h"
#include "MR001004.h"
#include "ViRHaS.h"

//input pins
#define _EP11 19
#define _EP12 18
#define _EP21 21
#define _EP22 20
#define _EP31 3
#define _EP32 2

//output pins
#define _1A 4
#define _1B 5
#define _1E 6
#define _2A 7
#define _2B 8
#define _2E 9
#define _3A 52
#define _3B 50
#define _3E 10

//max speeds
#define _MAX_SPEED 60 
#define _MAX_ANGULAR 2 

//motors
MR001004 m1m2 = MR001004(_1A, _1B, _1E, _2A, _2B, _2E);
MR001004 m3 = MR001004(_3A, _3B, _3E);

//encoders
Encoder ENCODER[] = { Encoder(_EP11, _EP12), Encoder(_EP21, _EP22), Encoder(_EP31, _EP32)};

//robot class
ViRHaS virhas = ViRHaS(m1m2, m3, ENCODER[0], ENCODER[1], ENCODER[2]);

//input buffer
char input_buffer[2000];
int buffer_index = 0;

//hang position
boolean move = false;

void setup(){
  Serial.begin(115200);
  
}

/*
  moves motor with a string
  a correct string is composed by 3 chars:
  first char is strafe versor
  second char is forward versor
  third char is angular versor
*/
void vectorFromString(char* string, int l){
  if(l<3)
    return;
    
  //else
  int data_s = (int)string[0];
  data_s-=50;
  int data_f = (int)string[1];
  data_f-=50;
  int data_a = (int)string[2];
  data_a-=50;
  
  float strafe = -(float)data_s/50;
  float forward = (float)data_f/50;
  float angular = (float)data_a/50;
  
  if(strafe==0 && forward==0 && angular==0){
    //if stop message is detected
    move = false;
    virhas.stop2();
  }
  else{
    move = true;
    virhas.run2(strafe*_MAX_SPEED, forward*_MAX_SPEED, angular*_MAX_ANGULAR);
  }
}

/*
  inserts input char in a buffer, then submits and resets
  the buffer if buffer terminator 'n' is read. 
*/
void bufferInput(char c){
  if(c == 'n'){
    vectorFromString(input_buffer, buffer_index);
    buffer_index = 0;
  }
  else{
    input_buffer[buffer_index] = c;
    buffer_index++;
  }
}

/*
  serial read loop
*/
void getparamLoop(){
  while(Serial.available()>0){
    bufferInput(Serial.read());
  }
}

/*
  pid loop
*/
void pidLoop() {
  if(move)
    virhas.PIDLoop();
}

void loop() {
  getparamLoop();
  pidLoop();
}
