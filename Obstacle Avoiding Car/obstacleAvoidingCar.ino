#include <Servo.h>          //library for the servo
#include <NewPing.h>        //Ultrasonic sensor function library.

//L298N motor control pins
const int LeftMotorFor = 6;
const int LeftMotorBack = 7;
const int RightMotorFor = 5;
const int RightMotorBack = 4;

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define max_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, max_distance); //sensor function
Servo servo_motor; 

void setup(){

  pinMode(RightMotorFor, OUTPUT);
  pinMode(LeftMotorFor, OUTPUT);
  pinMode(LeftMotorBack, OUTPUT);
  pinMode(RightMotorBack, OUTPUT);
  
  servo_motor.attach(9); //our servo pin

  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorFor, LOW);
  digitalWrite(LeftMotorFor, LOW);
  digitalWrite(RightMotorBack, LOW);
  digitalWrite(LeftMotorBack, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorFor, HIGH);
    digitalWrite(RightMotorFor, HIGH);
  
    digitalWrite(LeftMotorBack, LOW);
    digitalWrite(RightMotorBack, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBack, HIGH);
  digitalWrite(RightMotorBack, HIGH);
  
  digitalWrite(LeftMotorFor, LOW);
  digitalWrite(RightMotorFor, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorFor, HIGH);
  digitalWrite(RightMotorBack, HIGH);
  
  digitalWrite(LeftMotorBack, LOW);
  digitalWrite(RightMotorFor, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorFor, HIGH);
  digitalWrite(RightMotorFor, HIGH);
  
  digitalWrite(LeftMotorBack, LOW);
  digitalWrite(RightMotorBack, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBack, HIGH);
  digitalWrite(RightMotorFor, HIGH);
  
  digitalWrite(LeftMotorFor, LOW);
  digitalWrite(RightMotorBack, LOW);

  delay(500);
  
  digitalWrite(LeftMotorFor, HIGH);
  digitalWrite(RightMotorFor, HIGH);
  
  digitalWrite(LeftMotorBack, LOW);
  digitalWrite(RightMotorBack, LOW);
}
