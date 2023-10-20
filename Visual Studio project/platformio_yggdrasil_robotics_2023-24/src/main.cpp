#include "motorHeaders/motorHeader.hpp"

motorController motorControl;

void setup() {
  motorControl.DeviceDriverSetMotorInit();
}

//Prueba
void loop() {
  motorControl.allMotorsRunning(true);
  motorControl.leftMotorsForward(true, 1);
  motorControl.rightMotorsForward(false, 1);
}
