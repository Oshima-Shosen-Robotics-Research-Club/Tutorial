#include "Tires.h"
#include <components/ims/ImReceiver.h>
#include "controller/Controller.h"
#include <Arduino.h>

#define RX PD6
#define TX PD7

ImReceiver imReceiver(RX, TX);

void setup() {
}

void loop() {
  while (!imReceiver.available()) {
    delay(100);
  }

  Controller controller;
  imReceiver.receive(controller);

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