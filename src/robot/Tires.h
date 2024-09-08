#ifndef TIRES_H
#define TIRES_H

#include "components/motors/BD62193.h"

class Tires {
private:
  static BD62193 turnMotor;
  static BD62193 leftMotor;
  static BD62193 rightMotor;

public:
  static void forward();
  static void reverse();
  static void turnLeft();
  static void turnRight();
  static void stop();
};

#endif // TIRES_H