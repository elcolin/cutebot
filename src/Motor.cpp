#include "Motor.h"

Motor::Motor()
{
}

void Motor::setMotorSpeed(int8_t motorSpeed)
{
    int8_t direction = motorSpeed > 0 ? 0x02 : 0x01;
    Wire.beginTransmission(0x10);
    Wire.write(id_ + 1);
    Wire.write(direction);
    Wire.write(motorSpeed);
    Wire.TwoWire::write(static_cast<uint8_t>(0));
    Wire.endTransmission();
}