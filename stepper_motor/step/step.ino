/*

Spring 2022 Senior Design Project
Team FH17
Authors: Alex Riehm, Jacob Dach, Jason Fry, Justn Kim, Matthew Withey, Tom Li

*/

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

int com;
bool move = true;

// setup logic of pins
void setup() {
  pinMode(dirMotor_1_pin,OUTPUT); 
  pinMode(stepMotor_1_pin,OUTPUT);
  pinMode(dirMotor_2_pin,OUTPUT); 
  pinMode(stepMotor_2_pin,OUTPUT);
  pinMode(wait_pin, OUTPUT);
  pinMode(ready_pin, INPUT); 
  Serial.begin(9600);
}

// main loop for program
void loop() {
  while(Serial.available()==0) {}
  com = Serial.read();
  
  switch(com) {

    case 'e': {
      digitalWrite(stepMotor_1_pin,LOW); 
      delayMicroseconds(500); 
      break;
    }

    case 'a': {
      digitalWrite(dirMotor_1_pin,HIGH);
      for(int x = 0; x < 100; x++) {
        digitalWrite(stepMotor_1_pin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepMotor_1_pin,LOW); 
        delayMicroseconds(500); 
      }
      break;
    }

    case 'd': {
      digitalWrite(dirMotor_1_pin,LOW);
      for(int x = 0; x < 100; x++) {
        digitalWrite(stepMotor_1_pin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepMotor_1_pin,LOW); 
        delayMicroseconds(500); 
      }
      break;
    }

    case 'w': {
      digitalWrite(dirMotor_2_pin,HIGH);
      for(int x = 0; x < 100; x++) {
        digitalWrite(stepMotor_2_pin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepMotor_2_pin,LOW); 
        delayMicroseconds(500); 
      }
      break;
    }

    case 's': {
      digitalWrite(dirMotor_2_pin,LOW);
      for(int x = 0; x < 100; x++) {
        digitalWrite(stepMotor_2_pin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepMotor_2_pin,LOW); 
        delayMicroseconds(500); 
      }
      break;
    }

  }  
  
}


// **Use this section for notes** //
/* 

Thinking about using some sort of finite state machine for the program

*/