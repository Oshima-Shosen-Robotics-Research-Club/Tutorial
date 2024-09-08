#include "Tires.h"

BD62193 Tires::turnMotor(PD0, PD1);
BD62193 Tires::leftMotor(PD2, PD3);
BD62193 Tires::rightMotor(PD4, PD5);

void Tires::forward() {
  leftMotor.forward();
  rightMotor.forward();
}

void Tires::reverse() {
  leftMotor.reverse();
  rightMotor.reverse();
}

void Tires::turnLeft() { 
    turnMotor.forward(); 
}

void Tires::turnRight() {
    turnMotor.reverse(); 
}

void Tires::stop() {
  leftMotor.stop();
  rightMotor.stop();
}