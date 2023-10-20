#include <arduino.h>

class lineTracker {
  private:
    #define leftTrackingCameraPin A2
    #define mediumTrackingCameraPin A1
    #define rightTrackingCameraPin A0

  public:
    bool lineTrackerInit(void);
    float getLeftTrackingCameraMeasure(void);
    float getMediumTrackingCameraMeasure(void);
    float getRightTrackingCameraMeasure(void);
};
