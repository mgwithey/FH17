/*

Spring 2022 Senior Design Project
Team FH17
Authors: Alex Riehm, Jacob Dach, Jason Fry, Justn Kim, Matthew Withey, Tom Li

*/

#include <AccelStepper.h>
#include <ezButton.h>

// defining all global constants
// pinout for motor direction logic
const int dirMotor_1_pin = 2;
const int dirMotor_2_pin = 4;

// pinout for motor step logic
const int stepMotor_1_pin = 3;
const int stepMotor_2_pin = 5;

char current_case;
int X_SCALAR = -275;
int Y_SCALAR = 275;
int MAX_XLOC = X_SCALAR*100;
int MAX_YLOC = Y_SCALAR*100;
int loc[] = {0,0};
bool done = false;
bool homeFound = false;

const int MAXSPEED = 1000;
const int MAXACCEL = 1000;
const int distance = 500;

AccelStepper motorH(1, stepMotor_1_pin, dirMotor_1_pin);
AccelStepper motorV(1, stepMotor_2_pin, dirMotor_2_pin);

ezButton limitSwitch(7);

// setup logic of pins, open serial port
void setup() {
  pinMode(dirMotor_1_pin,OUTPUT); 
  pinMode(stepMotor_1_pin,OUTPUT);
  pinMode(dirMotor_2_pin,OUTPUT); 
  pinMode(stepMotor_2_pin,OUTPUT);

  motorH.setMaxSpeed(MAXSPEED);
  motorH.setAcceleration(MAXACCEL);
  motorH.setCurrentPosition(0);

  motorV.setMaxSpeed(MAXSPEED);
  motorV.setAcceleration(MAXACCEL);
  motorV.setCurrentPosition(0);

  limitSwitch.setDebounceTime(50);
  
  done = false;
  homeFound = false;
  Serial.begin(9600);
}

void getUserInput() {
  String userData;
  String new_X;
  String new_Y;
  String findBreak;
  int breakInt = 0;
  
  delay(200);
  userData = Serial.readString();

  findBreak = userData.indexOf('-');
  breakInt = findBreak.toInt();

  new_X = userData;
  new_X.remove(breakInt);

  new_Y = userData;
  new_Y.remove(0, breakInt+1);

  loc[0] = new_X.toInt();
  loc[1] = new_Y.toInt();
  
}

bool checkPause() {
  if (Serial.available()>0) {
    String input;
    input = Serial.readString();
    return (input == "p");
  } else {
    return false;
  }
}

void takeMeasurment() {
  
  // whatever to take measurment here
  
  while(!done) {

    if (checkPause()) {
      return;
    }
    
    if (abs(loc[0]) >= abs(MAX_XLOC)) {
      if (loc[1] >= MAX_YLOC) {
        done = true;
        return;
      }
      loc[0] = 0;
      motorH.runToNewPosition(loc[0]);
      delay(100);
      loc[1] += Y_SCALAR;
      motorV.runToNewPosition(loc[1]);
      delay(100);
    } else {
      loc[0] += X_SCALAR;
      motorH.runToNewPosition(loc[0]);
      delay(100);
    }
  }
  return;
}

void reset() {
  motorH.stop();
  motorV.stop();
  motorH.runToNewPosition(0);
  motorV.runToNewPosition(0);
  done = false;
}

void findHome() {
  motorH.setSpeed(500);
  while(limitSwitch.getStateRaw()) {
    motorH.runSpeed();
  } 
  motorH.stop();
  loc[0] = 0;
  motorH.setCurrentPosition(0);
  motorH.runToNewPosition(X_SCALAR);
  motorH.setCurrentPosition(0);
  homeFound = true;
}

void demo() {
  for (int i = 0; i < 5; i++) {
    motorH.runToNewPosition(X_SCALAR*5*i);
    delay(100);
    motorV.runToNewPosition(Y_SCALAR*5*i);
    delay(100);
  }
}

// main loop for program
void loop() {
  delay(200);
  
  if (Serial.available()>0) {
    current_case = Serial.read();
    switch(current_case) {
      
      // run measurments
      case 's': {
        if (!homeFound) {
          findHome();
        }
        if (!done) {
          takeMeasurment();
        }
        break;
      }

      // reset case
      case 'r': {
        reset();
      }
      
      // move to new position based on user input
      case 'm': {
        getUserInput();
        if (!homeFound) {
          findHome();
        }
        motorH.runToNewPosition(loc[0]*X_SCALAR);
        delay(100);
        motorV.runToNewPosition(loc[1]*Y_SCALAR);
        delay(100);
        break;
      }
      
    }  
  }
}
