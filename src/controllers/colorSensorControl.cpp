#include "colorSensorHeader.hpp"

void colorSensor::colorSensorInit() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

int colorSensor::getRojo() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  int ROJO = pulseIn(out, LOW);
  return ROJO;
}

int colorSensor::getAzul() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  int AZUL = pulseIn(out, LOW);
  return AZUL;
}

int colorSensor::getVerde() {
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  int VERDE = pulseIn(out, LOW);
  return VERDE;
}

bool colorSensor::checkStopColor() {
  Color muestra(getRojo(), getVerde(), getAzul());

  for (int i = 2; i < 3; ++i) {
    if (franjas[i].inFranja(muestra)) { 
      return true;
    }
  }
  return false;
}
