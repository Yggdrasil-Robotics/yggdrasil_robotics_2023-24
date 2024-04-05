#include <Arduino.h>

class colorSensor {
    private:
    #define s0 4
    #define s1 5
    #define s2 6
    #define s3 7
    #define out 8
    
    public:
    void colorSensorInit();

    int getRojo();
    int getAzul();
    int getVerde();
};
