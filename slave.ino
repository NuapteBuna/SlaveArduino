#include <SoftwareSerial.h>
#include "comm.h"

void setup(){
    Serial.begin(9600);
    Com.Begin();
    Serial.println("Started");
}

void loop(){
    Com.Receive();
}