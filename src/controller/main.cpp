#include "Controller.h"
#include <Arduino.h>
#include <components/ims/IM920SL.h>

// ピン定義
#define FORWARD_PIN PIN_PD4
#define REVERSE_PIN PIN_PD5
#define LEFT_PIN PIN_PD6
#define RIGHT_PIN PIN_PD7

SerialPort serialPort(Serial);
ImSender im(serialPort);

// 一度だけ実行される処理
void setup() {
  pinMode(FORWARD_PIN, INPUT_PULLUP);
  pinMode(REVERSE_PIN, INPUT_PULLUP);
  pinMode(LEFT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);
  im.begin();
}

// 繰り返し実行される処理
void loop() {
  Controller controller;
  controller.forward = !digitalRead(FORWARD_PIN);
  controller.reverse = !digitalRead(REVERSE_PIN);
  controller.left = !digitalRead(LEFT_PIN);
  controller.right = !digitalRead(RIGHT_PIN);
  im.send(controller);
  delay(100);
}