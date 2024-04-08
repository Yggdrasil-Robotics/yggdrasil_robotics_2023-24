#include "ultrasonicSensorHeader.hpp"

void ultrasonicSensor::ultrasonicSensorInit() {
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
}

int ultrasonicSensor::getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  return ((unsigned int)pulseIn(ECHO_PIN, HIGH) / 58);
}
