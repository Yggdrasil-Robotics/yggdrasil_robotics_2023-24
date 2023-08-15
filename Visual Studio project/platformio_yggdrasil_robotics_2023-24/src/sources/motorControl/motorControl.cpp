#include "motorHeader/motorHeader.hpp"

void motorController::DeviceDriverSetMotorInit(void) {
  pinMode(rightMotorsSpeedPin, OUTPUT);
  pinMode(leftMotorsSpeedPin, OUTPUT);
  pinMode(rightMotorsDirectionPin, OUTPUT);
  pinMode(leftMotorsDirectionPin, OUTPUT);
  pinMode(allMotorsStandByPin, OUTPUT);
}

void motorController::allMotorsRunning(boolean motorsRunning) {
  digitalWrite(allMotorsStandByPin, motorsRunning);
}

uint8_t motorController::speedRestrictionControl(uint8_t speed) {
  return min(max(speed, minSpeed), maxSpeed);
}

void motorController::rightMotorsForward(boolean forward, uint8_t speed) {
  digitalWrite(rightMotorsDirectionPin, forward);
  analogWrite(rightMotorsSpeedPin, speedRestrictionControl(speed));
}

void motorController::leftMotorsForward(boolean forward, uint8_t speed) {
  digitalWrite(leftMotorsDirectionPin, forward);
  analogWrite(leftMotorsSpeedPin, speedRestrictionControl(speed));
}
