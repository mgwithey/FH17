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

// setup logic of pins
void setup() {
  pinMode(dirMotor_1_pin,OUTPUT); 
  pinMode(stepMotor_1_pin,OUTPUT);
  pinMode(dirMotor_2_pin,OUTPUT); 
  pinMode(stepMotor_2_pin,OUTPUT);
  pinMode(wait_pin, OUTPUT);
  pinMode(ready_pin, INPUT); 
  Serial.begin(9600);
  Serial.println('Starting program');
}

// main loop for program
void loop() {
  digitalWrite(dirMotor_1_pin,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepMotor_1_pin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepMotor_1_pin,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000);
  
  digitalWrite(dirMotor_1_pin,LOW);
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepMotor_1_pin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepMotor_1_pin,LOW);
    delayMicroseconds(500);
  }
  
  delay(1000);
}


// **Use this section for notes** //
/* 

Thinking about using some sort of finite state machine for the program

*/