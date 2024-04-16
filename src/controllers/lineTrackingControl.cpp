#include "lineTrackingHeader.hpp"

void lineTracker::lineTrackerInit() {
    pinMode(leftTrackingCameraPin, INPUT);
    pinMode(mediumTrackingCameraPin, INPUT);
    pinMode(rightTrackingCameraPin, INPUT);
}

float lineTracker::getLeftTrackingCameraMeasure() {
    return analogRead(leftTrackingCameraPin);
}

float lineTracker::getMediumTrackingCameraMeasure() {
    return analogRead(mediumTrackingCameraPin);
}

float lineTracker::getRightTrackingCameraMeasure() {
    return analogRead(rightTrackingCameraPin);
}

int lineTracker::trackingMode(lineTracker lineTrack) {
    float lineTrackLeft = lineTrack.getLeftTrackingCameraMeasure();
    float lineTrackMedium = lineTrack.getMediumTrackingCameraMeasure();
    float lineTrackRight = lineTrack.getRightTrackingCameraMeasure();

    if(lineTrackLeft < 950 && lineTrackMedium < 950 && lineTrackRight < 950) {
        if(lineTrackLeft > 500) {
            return 0;
        } else if(lineTrackMedium > 500) {
            return 1;
        } else if(lineTrackRight > 500) {
            return 2;
        }
    } else {
        return -1;
    }
}
