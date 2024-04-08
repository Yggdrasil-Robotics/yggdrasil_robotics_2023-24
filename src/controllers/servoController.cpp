#include "servoHeader.hpp"
#include <Arduino.h>

Servo myservo;

void servoMotor::servoMotorInit(unsigned int Position_angle) {
  myservo.attach(PIN_Servo_z, 500, 2400); //500=0 degree, 2400=180 degree
  myservo.attach(PIN_Servo_z);
  myservo.write(Position_angle); //sets the servo position according to the 90（middle）
  delay(500);
}

void servoMotor::DeviceDriverSet_Servo_control(unsigned int Position_angle) {
  myservo.attach(PIN_Servo_z);
  myservo.write(Position_angle);
  delay(100);
  myservo.detach();
}
