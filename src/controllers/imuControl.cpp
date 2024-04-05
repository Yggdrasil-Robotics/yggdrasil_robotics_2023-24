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

  // Make sure slave device is online
  do {
    chipID = accelgyro.getDeviceID();
    attempts++;

    if (attempts > 1000) {
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

  for (int i = 0; i < totalSamples; i++)
  {
    gyroscopeOffset += accelgyro.getRotationZ();
  }

  // Calculate gyroscope displacement
  gyroscopeOffset /= totalSamples;
}

float MPU6050_getdata::MPU6050GetEulerAngles() {
  unsigned long actualTime = millis();
  float actualAngle = 0;

  differentialTime = (actualTime - lastTime) / 1000.0;
  lastTime = actualTime;
  // Z axis angular velocity
  actualAngle = -(accelgyro.getRotationZ() - gyroscopeOffset) / 131.0 * differentialTime;

  // Delete noise
  if (fabs(actualAngle) < 0.05)
    actualAngle = 0.00;

  return actualAngle;
}
