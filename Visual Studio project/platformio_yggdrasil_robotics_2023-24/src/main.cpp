#include "motorControl/motorControl.hpp"

motorController motorControl;

void setup() {
  motorControl.DeviceDriverSetMotorInit();
}

void loop() {
  motorControl.allMotorsRunning(true);
  motorControl.leftMotorsForward(true, 1);
  motorControl.rightMotorsForward(false, 1);
}
