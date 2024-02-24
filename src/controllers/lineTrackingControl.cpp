#include "lineTrackingHeader.hpp"

void lineTracker::lineTrackerInit()
{
  pinMode(leftTrackingCameraPin, INPUT);
  pinMode(mediumTrackingCameraPin, INPUT);
  pinMode(rightTrackingCameraPin, INPUT);
}

float lineTracker::getLeftTrackingCameraMeasure()
{
  return analogRead(leftTrackingCameraPin);
}

float lineTracker::getMediumTrackingCameraMeasure()
{
  return analogRead(mediumTrackingCameraPin);
}

float lineTracker::getRightTrackingCameraMeasure()
{
  return analogRead(rightTrackingCameraPin);
}
