#include <Arduino.h>

class ultrasonicSensor {
    private:
    #define TRIG_PIN 13
    #define ECHO_PIN 12
    
    public:
    void ultrasonicSensorInit();
    int getDistance();
};
