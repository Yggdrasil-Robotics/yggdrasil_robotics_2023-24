#include <arduino.h>

class motorController {
  private:
    #define minSpeed 75
    #define maxSpeed 255
    #define rightMotorsSpeedPin     5
    #define leftMotorsSpeedPin      6
    #define leftMotorsDirectionPin  8 //HIGH to move forward, LOW to move backward
    #define rightMotorsDirectionPin 7 //HIGH to move forward, LOW to move backward
    #define allMotorsStandByPin     3 //HIGH to work, LOW to stop
  
  public:
    void DeviceDriverSetMotorInit(void);
    void allMotorsRunning(boolean motorsRunning);
    uint8_t speedRestrictionControl(uint8_t speed);
    void rightMotorsForward(boolean forward, uint8_t speed);
    void leftMotorsForward(boolean forward, uint8_t speed);
};