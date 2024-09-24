#include "controller/Controller.h"
#include <Arduino.h>
#include <components/ims/IM920SL.h>
#include <components/motors/NonSpeedAdjustable.h>

SerialPort serialPort(Serial);
ImReceiver im(serialPort);

// 前輪
NonSpeedAdjustable frontWheel(PIN_PD2, PIN_PD3);
// 後輪L
NonSpeedAdjustable rearWheelL(PIN_PD4, PIN_PD5);
// 後輪R
NonSpeedAdjustable rearWheelR(PIN_PD6, PIN_PD7);

void setup() { im.begin(); }

void loop() {
  while (!im.available()) {
    delay(100);
  }

  Controller controller;
  im.receive(controller);

  if (controller.forward) {
    rearWheelL.forward();
    rearWheelR.forward();
  } else if (controller.reverse) {
    rearWheelL.reverse();
    rearWheelR.reverse();
  } else {
    rearWheelL.stop();
    rearWheelR.stop();
  }

  if (controller.left) {
    frontWheel.forward();
  } else if (controller.right) {
    frontWheel.reverse();
  } else {
    frontWheel.stop();
  }
}