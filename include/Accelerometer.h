#include <Arduino.h>
#include <Wire.h>
#include "HardwareConfig.h"

enum AXIS {
    X,
    Y,
    Z,
    AXIS_COUNT
};

class Accelerometer {
    public:
        Accelerometer();
        void updateData();
        void begin();
        void printData();
    private:
        int16_t axisData_[AXIS_COUNT] = {0};
};