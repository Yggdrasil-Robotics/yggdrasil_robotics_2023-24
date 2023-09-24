#include <Arduino.h>

class MPU6050_getdata {
  private:
    //float pith, roll, yaw;
    unsigned long lastTime = 0;
    float differentialTime;
    float expectedAngle = 0;
    long gyroscopeOffset = 0;
    
  public:
    bool MPU6050Init(void);
    void MPU6050Calibration(void);
    float MPU6050GetEulerAngles();
};
