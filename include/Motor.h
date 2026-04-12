#include <Arduino.h>
#include <Wire.h>

enum MotorDirection {
    FORWARD = 0x02,
    BACKWARD = 0x01
};

enum MotorSide : int {
    LEFT,
    RIGHT,
    MOTOR_COUNT
};

class Motor{
    public:
        Motor();
        void setMotorSpeed(int8_t motorSpeed);
        void setId(MotorSide id) { id_ = id; };
    protected:
        int8_t motorSpeed_;
        MotorSide id_;
};