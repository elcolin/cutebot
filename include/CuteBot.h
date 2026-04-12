#include <Arduino.h>
#include "Motor.h"

#define SONAR_TRIG_PIN 8
#define SONAR_ECHO_PIN 12
#define CUTEBOT_ADDR 0x10

class CuteBot {

    public:
        CuteBot();
        void begin();
        long getDistance();
        void turnLeft();
        void turnRight();
    private:
        Motor motors_[MOTOR_COUNT];
        long lastDistance_;
};