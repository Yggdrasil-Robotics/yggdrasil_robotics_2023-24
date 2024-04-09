#include "motorHeader.hpp"
#include "lineTrackingHeader.hpp"
#include "colorSensorHeader.hpp"
#include "ultrasonicSensorHeader.hpp"
#include "servoHeader.hpp"

motorController motorControl;
lineTracker lineTrack;
colorSensor colorCheck;
ultrasonicSensor sonicSensor;
servoMotor servo;

void setup() {
  motorControl.DeviceDriverSetMotorInit();
  lineTrack.lineTrackerInit();
  sonicSensor.ultrasonicSensorInit();
  servo.servoMotorInit(90);

  while(digitalRead(23) == LOW) {} // waiting until the blocker is released
}

void loop() {
  int back = 170;

  for(int i = 0; i <= 360; i += 10) {
    if(i <= 180) {
      servo.servoPosition(i);
    } else {
      servo.servoPosition(back);
      back -= 10;
    }

    if(sonicSensor.getDistance() < 35 || colorCheck.checkStopColor()) {
      motorControl.stopMotor();
      
      while(sonicSensor.getDistance() < 35) {}
      servo.servoMotorInit(90);
    } else {
      motorControl.startMotor();
      motorControl.lineTrackMode(lineTrack.trackingMode(lineTrack));
    }
  }
}
