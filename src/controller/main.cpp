#include "Controller.h"
#include <components/ims/ImSender.h>
#include <Arduino.h>

// ピン定義
#define RX PD2
#define TX PD3
#define FORWARD_PIN PD4
#define REVERSE_PIN PD5
#define LEFT_PIN PD6
#define RIGHT_PIN PD7

ImSender imSender(RX, TX);

// 一度だけ実行される処理
void setup() {
  pinMode(FORWARD_PIN, INPUT_PULLUP);
  pinMode(REVERSE_PIN, INPUT_PULLUP);
  pinMode(LEFT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);
}

// 繰り返し実行される処理
void loop() {
  Controller controller;
  controller.forward = !digitalRead(FORWARD_PIN);
  controller.reverse = !digitalRead(REVERSE_PIN);
  controller.left = !digitalRead(LEFT_PIN);
  controller.right = !digitalRead(RIGHT_PIN);
  imSender.send(controller);
  delay(100);
}