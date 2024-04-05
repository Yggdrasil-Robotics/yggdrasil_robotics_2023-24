#include "motorHeader.hpp"

void motorController::DeviceDriverSetMotorInit() {
  pinMode(rightMotorsSpeedPin, OUTPUT);
  pinMode(leftMotorsSpeedPin, OUTPUT);
  pinMode(rightMotorsDirectionPin, OUTPUT);
  pinMode(leftMotorsDirectionPin, OUTPUT);
  pinMode(allMotorsStandByPin, OUTPUT);
}

void motorController::startMotor() {
  digitalWrite(allMotorsStandByPin, true);
}

void motorController::stopMotor() {
  analogWrite(rightMotorsSpeedPin, 0);
  analogWrite(leftMotorsSpeedPin, 0);

  digitalWrite(allMotorsStandByPin, false);
}

uint8_t motorController::speedRestrictionControl(uint8_t speed) {
  return min(max(speed, minSpeed), maxSpeed);
}

void motorController::rightMotorsForward(boolean forward, uint8_t speed) {
  digitalWrite(rightMotorsDirectionPin, forward);
  analogWrite(rightMotorsSpeedPin, speedRestrictionControl(speed));
  rightSpeed = speed;
}

void motorController::leftMotorsForward(boolean forward, uint8_t speed) {
  digitalWrite(leftMotorsDirectionPin, forward);
  analogWrite(leftMotorsSpeedPin, speedRestrictionControl(speed));
  leftSpeed = speed;
}

void motorController::allMotorsStraightLine(boolean forward, uint8_t speed) {
  rightMotorsForward(forward, speed);
  leftMotorsForward(forward, speed);
}

void  motorController::lineTrackMode(int direction) {
  if(direction == 0) {
      leftMotorsForward(false, 80);
      rightMotorsForward(true, 80);
    } else if(direction == 1) {
      allMotorsStraightLine(true, 100);
    } else if(direction == 2) {
      leftMotorsForward(true, 80);
      rightMotorsForward(false, 80);
    } else {
      stopMotor();
    }
}
