#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "imuHeader.hpp"
#include <stdio.h>
#include <math.h>

MPU6050 accelgyro;
MPU6050_getdata MPU6050Getdata;

bool MPU6050_getdata::MPU6050Init() {
    uint8_t chipID = 0x00;
    int attempts = 0;

    Wire.begin();

    do {
        chipID = accelgyro.getDeviceID();
        Serial.println(chipID);
        attempts++;

        if (attempts > 10) {
            Serial.println("Connection error with the imu");
            return false;
        }
    } while (chipID == 0X00 || chipID == 0XFF);

    Serial.println("MPU6050 chip id: " + chipID);
    accelgyro.initialize();

    return true;
}

void MPU6050_getdata::MPU6050Calibration() {
    uint8_t totalSamples = 100;

    for (int i = 0; i < totalSamples; i++) {
        gyroscopeOffset += accelgyro.getRotationZ();
    }

    gyroscopeOffset /= totalSamples;
}

float MPU6050_getdata::MPU6050GetEulerAngles() {
    unsigned long actualTime = millis();
    float actualAngle = 0;

    differentialTime = (actualTime - lastTime) / 1000.0;
    lastTime = actualTime;

    actualAngle = -(accelgyro.getRotationZ() - gyroscopeOffset) / 131.0 * differentialTime;

    // Delete noise
    if (fabs(actualAngle) < 0.05)
        actualAngle = 0.00;
    
    return actualAngle;
}
