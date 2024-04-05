#include "motorHeader.hpp"
#include "lineTrackingHeader.hpp"

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
