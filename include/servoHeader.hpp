#include <Servo.h>

class servoMotor {
    private:
        const uint8_t PIN_Servo_z = 10;

    public:
        void servoMotorInit(unsigned int Position_angle);
        void servoPosition(unsigned int Position_angle);
};
