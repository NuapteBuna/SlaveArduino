#pragma once
#include <Pair.h>


/*
    1 2
    3 4
*/

enum DIRECTIONS {
    FORWARD = 2,
    FORWARD_LEFT = 1,
    FORWARD_RIGHT = 3,
    LEFT = 4,
    RIGHT = 5,
    BACKWARD = 7,
    BACKWARD_LEFT = 6,
    BACKWARD_RIGHT = 8,
    STOP = 0,
    NONE = -1,
    ROTATE_LEFT = 9,
    ROTATE_RIGHT = 10,
};

namespace MOTORS {
    struct motor1 {
        int pin1 = 8;
        int pin2 = 9;
        int speedpin = 12;
    };
    motor1 M1;
    
    struct motor2 {
        int pin1 = 10;
        int pin2 = 11;
        int speedpin = 13;
    };
    motor2 M2;
    
    struct motor3 {
        int pin1 = A5;
        int pin2 = A4;
        int speedpin = A1;
    };
    motor3 M3;

    struct motor4 {
        int pin1 = A3;
        int pin2 = A2;
        int speedpin = A0;
    };
    motor4 M4;

    void Initialize() {
        pinMode(M1.pin1, OUTPUT);
        pinMode(M1.pin2, OUTPUT);

        pinMode(M2.pin1, OUTPUT);
        pinMode(M2.pin2, OUTPUT);
        
        pinMode(M3.pin1, OUTPUT);
        pinMode(M3.pin2, OUTPUT);

        pinMode(M4.pin1, OUTPUT);
        pinMode(M4.pin2, OUTPUT);
    
        pinMode(M1.speedpin, OUTPUT);
        pinMode(M2.speedpin, OUTPUT);
        pinMode(M3.speedpin, OUTPUT);
        pinMode(M4.speedpin, OUTPUT);
    }

    void WriteSpeed(int speed1, int speed2, int speed3, int speed4){
        analogWrite(M1.speedpin, speed1);
        analogWrite(M2.speedpin, speed2);
        analogWrite(M3.speedpin, speed3);
        analogWrite(M4.speedpin, speed4);
    }

    void WriteDirection(Pair<int, int> m1, Pair<int, int> m2, Pair<int, int> m3, Pair<int, int> m4){
        digitalWrite(M1.pin1, m1.val_1);
        digitalWrite(M1.pin2, m1.val_2);

        digitalWrite(M2.pin1, m2.val_1);
        digitalWrite(M2.pin2, m2.val_2);
        
        digitalWrite(M3.pin1, m3.val_1);
        digitalWrite(M3.pin2, m3.val_2);
        
        digitalWrite(M4.pin1, m4.val_1);
        digitalWrite(M4.pin2, m4.val_2);
    }

    void Move(DIRECTIONS direction, int speed){    
        Pair<int, int> m1(LOW, LOW);
        Pair<int, int> m2(LOW, LOW);
        Pair<int, int> m3(LOW, LOW);
        Pair<int, int> m4(LOW, LOW);
        WriteSpeed(speed, speed, speed, speed);
    
        if(direction == STOP){
            WriteSpeed(0, 0, 0, 0);
            m1.val_1 = LOW;
            m1.val_2 = LOW;

            m2.val_1 = LOW;
            m1.val_2 = LOW;

            m3.val_1 = LOW;
            m3.val_2 = LOW;

            m4.val_1 = LOW;
            m4.val_2 = LOW;
            WriteDirection(m1, m2, m3, m4);
        }

        if(direction == FORWARD){
            m1.val_1 = HIGH;
            m1.val_2 = LOW;

            m2.val_1 = HIGH;
            m1.val_2 = LOW;

            m3.val_1 = HIGH;
            m3.val_2 = LOW;

            m4.val_1 = HIGH;
            m4.val_2 = LOW;

            WriteDirection(m1, m2, m3, m4);
        }

        if(direction == BACKWARD){
            m1.val_1 = LOW;
            m1.val_2 = HIGH;

            m2.val_1 = LOW;
            m2.val_2 = HIGH;

            m3.val_1 = LOW;
            m3.val_2 = HIGH;

            m4.val_1 = LOW;
            m4.val_2 = HIGH;

            WriteDirection(m1, m2, m3, m4);
        }

        if(direction == ROTATE_RIGHT){
            m1.val_1 = HIGH;
            m1.val_2 = LOW;

            m2.val_1 = LOW;
            m2.val_2 = HIGH;

            m3.val_1 = HIGH;
            m3.val_2 = LOW;

            m4.val_1 = LOW;
            m4.val_2 = HIGH;

            WriteDirection(m1, m2, m3, m4);
        }

        if(direction == ROTATE_LEFT){
            m1.val_1 = LOW;
            m1.val_2 = HIGH;

            m2.val_1 = HIGH;
            m2.val_2 = LOW;

            m3.val_1 = LOW;
            m3.val_2 = HIGH;

            m4.val_1 = HIGH;
            m4.val_2 = LOW;

            WriteDirection(m1, m2, m3, m4);
        }

        if(direction == RIGHT){
            m1.val_1 = HIGH;
            m1.val_2 = LOW;

            m2.val_1 = LOW;
            m2.val_2 = HIGH;
 
            m3.val_1 = LOW;
            m3.val_2 = HIGH;

            m4.val_1 = HIGH;
            m4.val_2 = LOW;
                        
            WriteDirection(m1, m2, m3, m4);
        }

        if(direction == LEFT){
            m1.val_1 = LOW;
            m1.val_2 = HIGH;

            m2.val_1 = HIGH;
            m2.val_2 = LOW;
 
            m3.val_1 = HIGH;
            m3.val_2 = LOW;

            m4.val_1 = LOW;
            m4.val_2 = HIGH;
            
            WriteDirection(m1, m2, m3, m4);
        }
    }

    void HandleRemote(char input, int speed){
        DIRECTIONS current = STOP;
        if(input == 'h'){
            current = ROTATE_LEFT;
        }
        else if(input == 'j'){
            current = ROTATE_RIGHT;
        }
        else if(input == 'a'){
            current = LEFT;
        }
        else if(input == 'd'){
            current = RIGHT;
        }
        else if(input == 'w'){
            current = FORWARD;
        }
        else if(input == 'x'){
            current = BACKWARD;
        }
        else if(input == 'q'){
            current = FORWARD_LEFT;
        }
        else if(input == 'e'){
            current = FORWARD_RIGHT;
        }
        else if(input == 'z'){
            current = BACKWARD_LEFT;
        }
        else if(input == 'c'){
            current = BACKWARD_RIGHT;
        }
        Move(current, speed);
    }
};