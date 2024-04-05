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
  int movement = lineTrack.trackingMode(lineTrack);

  if(movement == 0) {
      motorControl.leftMotorsForward(false, 80);
      motorControl.rightMotorsForward(true, 80);
    } else if(movement == 1) {
      motorControl.allMotorsStraightLine(true, 100);
    } else if(movement == 2) {
      motorControl.leftMotorsForward(true, 80);
      motorControl.rightMotorsForward(false, 80);
    } else {
      motorControl.stopMotor();
    }
}
