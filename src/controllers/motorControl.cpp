#include "motorHeader.hpp"

/**
 * Asignación de pines
 */
void motorController::DeviceDriverSetMotorInit() {
  pinMode(rightMotorsSpeedPin, OUTPUT);
  pinMode(leftMotorsSpeedPin, OUTPUT);
  pinMode(rightMotorsDirectionPin, OUTPUT);
  pinMode(leftMotorsDirectionPin, OUTPUT);
  pinMode(allMotorsStandByPin, OUTPUT);
}

/**
 * Arrancar motor
 * Al hacer esto, los pines correspondientes estarán a la espera de ordenes
 */
void motorController::startMotor() {
  digitalWrite(allMotorsStandByPin, true);
}

/**
 * Pone a cero las velocidades de los motores y para el motor
 */
void motorController::stopMotor() {
  analogWrite(rightMotorsSpeedPin, 0);
  analogWrite(leftMotorsSpeedPin, 0);

  digitalWrite(allMotorsStandByPin, false);
}

/**
 * Se corrige la velocidad si su valor está fuera de los rangos válidos
 */
uint8_t motorController::speedRestrictionControl(uint8_t speed) {
  return min(max(speed, minSpeed), maxSpeed);
}

/**
 * Asigna velocidad y dirección a los motores de la derecha
 */
void motorController::rightMotorsForward(boolean forward, uint8_t speed) {
  digitalWrite(rightMotorsDirectionPin, forward);
  analogWrite(rightMotorsSpeedPin, speedRestrictionControl(speed));
  rightSpeed = speed;
}

/**
 * Asigna velocidad y dirección a los motores de la izquierda
 */
void motorController::leftMotorsForward(boolean forward, uint8_t speed) {
  digitalWrite(leftMotorsDirectionPin, forward);
  analogWrite(leftMotorsSpeedPin, speedRestrictionControl(speed));
  leftSpeed = speed;
}

/**
 * Asigna velocidad y dirección a ambos motores
 */
void motorController::allMotorsStraightLine(boolean forward, uint8_t speed) {
  rightMotorsForward(forward, speed);
  leftMotorsForward(forward, speed);
}
