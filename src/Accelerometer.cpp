#include "Accelerometer.h"

Accelerometer::Accelerometer()
{

}

void Accelerometer::begin()
{
    Wire1.begin();
    // Enable accelerometer
    Wire1.beginTransmission(ACC_ADDR);
    Wire1.write(0x20);  // CTRL_REG1
    Wire1.write(0x57);  // enable X/Y/Z
    Wire1.endTransmission();
}

void Accelerometer::printData()
{
    Serial.print("X: "); Serial.print(this->axisData_[X]);
    Serial.print(" Y: "); Serial.print(this->axisData_[Y]);
    Serial.print(" Z: "); Serial.println(this->axisData_[Z]);
}

void Accelerometer::updateData()
{
    Wire1.beginTransmission(ACC_ADDR);
    Wire1.write(0x28 | 0x80); // auto-increment read
    Wire1.endTransmission();

    // request 6 bytes (X/Y/Z)
    Wire1.requestFrom(ACC_ADDR, 6);

    if (Wire1.available() == 6) {

        this->axisData_[X] = Wire1.read() | (Wire1.read() << 8);
        this->axisData_[Y] = Wire1.read() | (Wire1.read() << 8);
        this->axisData_[Z] = Wire1.read() | (Wire1.read() << 8);
    }
}