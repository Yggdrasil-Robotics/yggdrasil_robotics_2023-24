#include <Arduino.h>

class motorController {
    private:
        const uint8_t minSpeed = 75;
        const uint8_t maxSpeed = 255;

        const uint8_t rightMotorsSpeedPin = 5;
        const uint8_t leftMotorsSpeedPin = 6;
        const uint8_t rightMotorsDirectionPin = 7; // HIGH to move forward, LOW to move backward
        const uint8_t leftMotorsDirectionPin = 8;  // HIGH to move forward, LOW to move backward

        const uint8_t allMotorsStandByPin = 3; // HIGH to work, LOW to stop

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
        void lineTrackMode(int direction);
};
