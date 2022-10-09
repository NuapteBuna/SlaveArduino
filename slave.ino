#include <SoftwareSerial.h>
#include "comm.h"

void setup(){
    Serial.begin(9600);
    Com.Begin();
}

bool testing = false;


void loop(){
    Serial.println(Com.received);


    Com.Receive();
    /*if(link.available()){
        //Com.ReadBytes(mystring, 8);
        
        Serial.println(mystring);
    }*/
    delay(1000);
}