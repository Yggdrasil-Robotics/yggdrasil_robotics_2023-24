#include <Arduino.h>

class lineTracker
{
private:
#define leftTrackingCameraPin A2
#define mediumTrackingCameraPin A1
#define rightTrackingCameraPin A0

public:
  void lineTrackerInit();

  float getLeftTrackingCameraMeasure();
  float getMediumTrackingCameraMeasure();
  float getRightTrackingCameraMeasure();
};
