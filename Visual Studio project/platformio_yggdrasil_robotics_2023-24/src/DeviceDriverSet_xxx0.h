#ifndef _DeviceDriverSet_xxx0_H_
#define _DeviceDriverSet_xxx0_H_
#include <arduino.h>

/*Motor*/
class DeviceDriverSet_Motor {
  public:
    void DeviceDriverSet_Motor_Init(void);

  #if _Test_DeviceDriverSet
    void DeviceDriverSet_Motor_Test(void);
  #endif
    void DeviceDriverSet_Motor_control(uint8_t rightDirection, uint8_t rightSpeed, boolean leftDirection, uint8_t leftSpeed);

  private:
  #define rightMotorsSpeedPin  5
  #define leftMotorsSpeedPin   6
  #define leftMotorsDirection  8 //HIGH to move forward, LOW to move backward
  #define rightMotorsDirection 7 //HIGH to move forward, LOW to move backward
  #define allMotorsStandBy     3 //HIGH to work, LOW to stop

  public:
  #define maxSpeed 255
  #define direction_just true
  #define direction_back false
  #define direction_void 3
};

#endif
