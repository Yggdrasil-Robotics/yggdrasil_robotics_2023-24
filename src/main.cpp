#include "motorHeader.hpp"
#include "lineTrackingHeader.hpp"
#include "colorSensorHeader.hpp"
#include "ultrasonicSensorHeader.hpp"

motorController motorControl;
lineTracker lineTrack;
colorSensor colorCheck;
ultrasonicSensor sonicSensor;

void setup() {
  motorControl.DeviceDriverSetMotorInit();
  lineTrack.lineTrackerInit();
  sonicSensor.ultrasonicSensorInit();
}

void loop() {
  if(sonicSensor.getDistance() < 35 || colorCheck.checkStopColor()) {
    motorControl.stopMotor();
  } else {
    motorControl.startMotor();
  }
  
  motorControl.lineTrackMode(lineTrack.trackingMode(lineTrack));
}
