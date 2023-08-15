#include <Arduino.h>

class MPU6050_getdata {
  private:
    //int16_t ax, ay, az, gx, gy, gz;
    int16_t gz;
    //float pith, roll, yaw;
    unsigned long now, lastTime = 0;
    //Differential time
    float dt;
    //Angle variable
    float agz = 0;
    //Gyroscope offset
    long gzo = 0;
    
  public:
    bool MPU6050_dveInit(void);
    bool MPU6050_calibration(void);
    bool MPU6050_dveGetEulerAngles(float *Yaw);
};
