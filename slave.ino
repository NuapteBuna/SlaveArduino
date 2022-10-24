#include <SoftwareSerial.h>
#include "comm.h"
#include <Servo.h>
#include "motors.h"

Servo bottom;
Servo arm1;
Servo arm2;
Servo small1;

void setup(){
    Serial.begin(9600);
    Com.Begin();
    Serial.println("Started");
    
    MOTORS::Initialize();
    
    //bottom.attach(7);
    //arm1.attach(8);
    //arm2.attach(9);
    //small1.attach(10);
}

int pos = 0;

int pos2 = 0;

void loop(){
    //MOTORS::Move(FORWARD, 130);
    //delay(3000);
    //MOTORS::Move(BACKWARD, 130);
    //delay(3000);
    //MOTORS::Move(RIGHT, 130);
    //delay(3000);

    Com.Receive();
    /*small1.write(0);
    arm2.write(0);
    arm1.write(0);
    bottom.write(0);
  delay(3000);
  small1.write(60);
  arm2.write(60);
  arm1.write(60);
  bottom.write(60);
  delay(3000);
  arm2.write(60);
  small1.write(120);
  arm1.write(120);
  bottom.write(120);*/
  
    /*for (pos = 0; pos <= 180; pos += 1) { 
    bottom.write(pos);               
    delay(15);                     
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    bottom.write(pos);              
    delay(15);                     
  }*/
    //Com.Receive();
}