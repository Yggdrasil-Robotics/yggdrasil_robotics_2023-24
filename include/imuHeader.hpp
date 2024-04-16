#include <Arduino.h>
#include "MPU6050.h"

class MPU6050_getdata {
    private:
        // float pith, roll, yaw;
        unsigned long lastTime = 0;
        float differentialTime;
        float expectedAngle = 0;
        long gyroscopeOffset = 0;

    public:
        bool MPU6050Init();
        void MPU6050Calibration();
        float MPU6050GetEulerAngles();
};
