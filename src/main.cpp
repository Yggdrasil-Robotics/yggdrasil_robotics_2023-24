#include "motorHeader.hpp"
#include "lineTrackingHeader.hpp"
#include "imuHeader.hpp"
#include "MPU6050.h"

motorController motorControl;
lineTracker lineTrack;

void setup() {
  motorControl.DeviceDriverSetMotorInit();
  lineTrack.lineTrackerInit();
}

void loop() {
  motorControl.startMotor();
  motorControl.lineTrackMode(lineTrack.trackingMode(lineTrack));
}
