// 他のファイルで実装された処理を流用するためにインクルード
#include "Controller.h"
#include <liboshima.h>

// ピン番号にボタンの名前を付ける
#define ZENTEN_BUTTON PIN_PD2
#define KOUTEN_BUTTON PIN_PD3

// IMを扱うための変数を作成
IM920SL im(Serial);

// 1回だけ実行される
void setup() {
  // 各ピンをボタンとして使えるように設定
  pinMode(ZENTEN_BUTTON, INPUT_PULLUP);
  pinMode(KOUTEN_BUTTON, INPUT_PULLUP);
  // IM920SLモジュールの通信を開始
  im.beginSerial();
}

// 繰り返し実行される
void loop() {
  // ボタンの状態を保持する変数を作成
  Controller controller;
  // 各ピンの状態を読み取り、controllerに格納
  if (digitalRead(ZENTEN_BUTTON) == LOW) {
    controller.motors[0] = MotorStateEnum::FORWARD;
  } else if (digitalRead(KOUTEN_BUTTON) == LOW) {
    controller.motors[0] = MotorStateEnum::REVERSE;
  } else {
    controller.motors[0] = MotorStateEnum::STOP;
  }
  // controllerを送信
  im.send(controller, ImSenderMode::CAREER_SENSE);
}