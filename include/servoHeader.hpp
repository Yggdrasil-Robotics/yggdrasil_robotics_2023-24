#include <Servo.h>

class servoMotor {
    private:
    #define PIN_Servo_z 10
    
    public:
    void servoMotorInit(unsigned int Position_angle);
    void DeviceDriverSet_Servo_control(unsigned int Position_angle);
};
