/*

Spring 2022 Senior Design Project
Team FH17
Authors: Alex Riehm, Jacob Dach, Jason Fry, Justn Kim, Matthew Withey, Tom Li

*/

#include <AccelStepper.h>

// defining all global constants
// pinout for motor direction logic
const int dirMotor_1_pin = 2;
const int dirMotor_2_pin = 4;

// pinout for motor step logic
const int stepMotor_1_pin = 3;
const int stepMotor_2_pin = 5;

// pinout for wait and ready signal
const int wait_pin = 6;
const int ready_pin = 7;

char current_case;
int previous_case;

const int MAXSPEED = 1000;
const int MAXACCEL = 500;
const int distance = 500;

AccelStepper motorH(1, stepMotor_1_pin, dirMotor_1_pin);
AccelStepper motorV(1, stepMotor_2_pin, dirMotor_2_pin);

// setup logic of pins, open serial port
void setup() {
  pinMode(dirMotor_1_pin,OUTPUT); 
  pinMode(stepMotor_1_pin,OUTPUT);
  pinMode(dirMotor_2_pin,OUTPUT); 
  pinMode(stepMotor_2_pin,OUTPUT);
  pinMode(wait_pin, OUTPUT);
  pinMode(ready_pin, INPUT); 

  motorH.setMaxSpeed(MAXSPEED);
  motorH.setAcceleration(MAXACCEL);
  motorH.setCurrentPosition(0);
  
  
  Serial.begin(9600);
}

// main loop for program
void loop() {
  if (Serial.available()>0) {
    current_case = Serial.read();
    
    switch(current_case) {

      // Exit the loop, close program
      case 'e': {
        digitalWrite(stepMotor_1_pin,LOW); 
        digitalWrite(stepMotor_2_pin,LOW);
        delayMicroseconds(500); 
        break;
      }

      // Move left
      case 'a': {
        motorH.runToNewPosition(motorH.currentPosition()+distance);
        break;
      }

      // Move right
      case 'd': {
        motorH.runToNewPosition(motorH.currentPosition()-distance);
        break;
      }

      // Move up
      case 'w': {
        break;
      }

      // Move down
      case 's': {
        break;
      }

    }  
  }
}


// **Use this section for notes** //
/* 

Thinking about using some sort of finite state machine for the program

*/