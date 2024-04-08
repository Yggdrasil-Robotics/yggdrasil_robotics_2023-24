#include <Servo.h>

class servoMotor {
    private:
    #define PIN_Servo_z 10

    public:
    void servoMotorInit(unsigned int Position_angle);
    void servoPosition(unsigned int Position_angle);
};
