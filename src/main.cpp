#include <Arduino.h>
#include "CuteBot.h"
#include "Accelerometer.h"

Accelerometer accel;
CuteBot cb;

const int buttonA = 5;     // the number of the pushbutton pin
const int buttonB = 11; 

void setup() {
    Serial.begin(9600);
    cb.begin();
    accel.begin();
    pinMode(buttonA, INPUT);  
    pinMode(buttonB, INPUT); 
}

void loop() {
    static bool start = false;
    // accel.updateData();
    //accel.printData();
    Serial.print("Distance: "); Serial.println(cb.getDistance());

    cb.getDistance();
    delay(200);
    if (! digitalRead(buttonA)) {
        Serial.println("Button A pressed");
        start = !start;
        delay(100);
    }
    if (start == false)
        return;
    cb.turnLeft();
    cb.turnRight();
    // set register pointer

}