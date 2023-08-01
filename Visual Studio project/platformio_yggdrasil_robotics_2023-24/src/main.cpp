#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"

DeviceDriverSet_Motor AppMotor;

void setup() {
  AppMotor.DeviceDriverSet_Motor_Init();
  delay(2000);
}

void loop() {
  AppMotor.DeviceDriverSet_Motor_control(1, 100, 1, 100);
  delay(8000);
}