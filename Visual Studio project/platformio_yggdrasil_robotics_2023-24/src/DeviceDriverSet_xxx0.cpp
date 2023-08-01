#include "DeviceDriverSet_xxx0.h"

/*Motor control*/
void DeviceDriverSet_Motor::DeviceDriverSet_Motor_Init(void) {
  pinMode(rightMotorsSpeedPin, OUTPUT);
  pinMode(leftMotorsSpeedPin, OUTPUT);
  pinMode(rightMotorsDirection, OUTPUT);
  pinMode(leftMotorsDirection, OUTPUT);
  pinMode(allMotorsStandBy, OUTPUT);
}

void DeviceDriverSet_Motor::DeviceDriverSet_Motor_control(uint8_t rightDirection, uint8_t rightSpeed, uint8_t leftDirection, uint8_t leftSpeed) {
  digitalWrite(allMotorsStandBy, HIGH);
  
  switch (rightDirection) {
    case 1:
      digitalWrite(rightMotorsDirection, HIGH);
      analogWrite(rightMotorsSpeedPin, rightSpeed);
      break;

    case 2:
      digitalWrite(rightMotorsDirection, LOW);
      analogWrite(rightMotorsSpeedPin, rightSpeed);
      break;

    default:
      analogWrite(rightMotorsSpeedPin, 0);
      digitalWrite(allMotorsStandBy, LOW);
      break;
  }

  switch (leftDirection) {
    case 1:
      digitalWrite(leftMotorsDirection, HIGH);
      analogWrite(leftMotorsSpeedPin, leftSpeed);
      break;

    case 2:
      digitalWrite(leftMotorsDirection, LOW);
      analogWrite(leftMotorsSpeedPin, leftSpeed);
      break;

    default:
      analogWrite(leftMotorsSpeedPin, 0);
      digitalWrite(allMotorsStandBy, LOW);
      break;
  }
}
