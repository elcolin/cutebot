#include "CuteBot.h"

CuteBot::CuteBot()
{
    motors_[LEFT].setId(LEFT);
    motors_[RIGHT].setId(RIGHT);
}

void CuteBot::begin()
{
    pinMode(SONAR_TRIG_PIN, OUTPUT);
    pinMode(SONAR_ECHO_PIN, INPUT);
    Wire.begin();
}

void CuteBot::turnLeft()
{
    motors_[LEFT].setMotorSpeed(lastDistance_ - 10);
}
void CuteBot::turnRight()
{
    motors_[RIGHT].setMotorSpeed(lastDistance_ - 10);
}

long CuteBot::getDistance()
{
    // Ensure clean start
    digitalWrite(SONAR_TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send trigger pulse (10 µs)
    digitalWrite(SONAR_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(SONAR_TRIG_PIN, LOW);

    // Measure echo pulse duration (timeout 25ms)
    long ts = pulseIn(SONAR_ECHO_PIN, HIGH, 25000);

    // Convert time to distance (cm)
    long distance = round(ts * 34.0 / 2.0 / 1000.0);
    lastDistance_ = distance;

    return distance; // cm
}