#include <Arduino.h>

class lineTracker {
    private:
        const uint8_t leftTrackingCameraPin = A2;
        const uint8_t mediumTrackingCameraPin = A1;
        const uint8_t rightTrackingCameraPin = A0;

    public:
        void lineTrackerInit();

        float getLeftTrackingCameraMeasure();
        float getMediumTrackingCameraMeasure();
        float getRightTrackingCameraMeasure();

        int trackingMode(lineTracker lineTrack);
};
