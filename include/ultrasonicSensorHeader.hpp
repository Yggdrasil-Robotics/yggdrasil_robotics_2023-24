#include <Arduino.h>

class ultrasonicSensor {
    private:
        const uint8_t TRIG_PIN = 13;
        const uint8_t ECHO_PIN = 12;
    
    public:
        void ultrasonicSensorInit();
        int getDistance();
};
