#include "motorHeader.hpp"

motorController motorControl;

void setup()
{
  motorControl.DeviceDriverSetMotorInit();
}

void loop()
{
  // Prueba --- v
  motorControl.startMotor();
  motorControl.leftMotorsForward(true, 1);
  motorControl.rightMotorsForward(false, 1);
  // Prueba --- ^
}
