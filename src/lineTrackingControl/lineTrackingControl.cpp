#include "lineTrackingHeaders/lineTrackingHeader.hpp"

void lineTracker::lineTrackerInit(void) {
  pinMode(leftTrackingCameraPin, INPUT);
  pinMode(mediumTrackingCameraPin, INPUT);
  pinMode(rightTrackingCameraPin, INPUT);
}

float lineTracker::getLeftTrackingCameraMeasure(void) {
  return analogRead(leftTrackingCameraPin);
}

float lineTracker::getMediumTrackingCameraMeasure(void) {
  return analogRead(mediumTrackingCameraPin);
}

float lineTracker::getRightTrackingCameraMeasure(void) {
  return analogRead(rightTrackingCameraPin);
}
