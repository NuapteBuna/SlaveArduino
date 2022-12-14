#pragma once
#include <SoftwareSerial.h>
#include "motors.h"
#define COM_PIN1 2
#define COM_PIN2 3

SoftwareSerial link(COM_PIN1, COM_PIN2);

struct COMMUNICATION {
    void Begin(int baud_rate = 9600);
    void Receive();
    void Write(char* buffer, int size);
    void ReadBytes(char* buffer, int size);
    void ReadString(String& buffer);
    char CurrentValue[100] = {""};
    String received = "";
};
COMMUNICATION Com;

void COMMUNICATION::Begin(int baud_rate = 9600){
    link.begin(baud_rate);
}

void COMMUNICATION::Receive(){
    received = "";
    if(link.available()){
        char c  = link.read();
        if(c == 'q' || c == 'w' || c == 'e' || c == 'a' || c == 's' || c == 'd' || c == 'z' || c == 'x' || c == 'c' || c == 'h' || c == 'j'){
            MOTORS::HandleRemote(c, 130);
        }        
    }
}

void COMMUNICATION::ReadBytes(char* buffer, int size){
    link.readBytes(buffer, size);
}

void COMMUNICATION::ReadString(String& buffer){
    buffer = link.readString();
}