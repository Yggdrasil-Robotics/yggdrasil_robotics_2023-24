#include "motorHeader.hpp"
#include "lineTrackingHeader.hpp"
#include "colorSensorHeader.hpp"

motorController motorControl;
lineTracker lineTrack;
colorSensor colorCheck;

void setup() {
  motorControl.DeviceDriverSetMotorInit();
  lineTrack.lineTrackerInit();

  motorControl.startMotor();
}

void loop() {
  if(colorCheck.checkStopColor()) {
    motorControl.stopMotor();
  }
  motorControl.lineTrackMode(lineTrack.trackingMode(lineTrack));
}
