#include <Arduino.h>

class motorController {
private:
#define minSpeed 75
#define maxSpeed 255

#define rightMotorsSpeedPin 5
#define leftMotorsSpeedPin 6
#define rightMotorsDirectionPin 7 // HIGH to move forward, LOW to move backward
#define leftMotorsDirectionPin 8  // HIGH to move forward, LOW to move backward

#define allMotorsStandByPin 3 // HIGH to work, LOW to stop

  // Current speed
  uint8_t rightSpeed;
  uint8_t leftSpeed;

public:
  void DeviceDriverSetMotorInit();

  void startMotor();
  void stopMotor();

  uint8_t speedRestrictionControl(uint8_t speed);

  void rightMotorsForward(boolean forward, uint8_t speed);
  void leftMotorsForward(boolean forward, uint8_t speed);
  void allMotorsStraightLine(boolean forward, uint8_t speed);
};
