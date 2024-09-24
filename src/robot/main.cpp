#include "Tires.h"
#include "controller/Controller.h"
#include <Arduino.h>
#include <components/ims/IM920SL.h>

SerialPort serialPort(Serial);
ImReceiver im(serialPort);

void setup() {}

void loop() {
  while (!im.available()) {
    delay(100);
  }

  Controller controller;
  im.receive(controller);

  if (controller.forward) {
    Tires::forward();
  } else if (controller.reverse) {
    Tires::reverse();
  } else {
    Tires::stop();
  }

  if (controller.left) {
    Tires::turnLeft();
  } else if (controller.right) {
    Tires::turnRight();
  }
}