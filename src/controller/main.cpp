// 他のファイルで実装された処理を流用するためにインクルード
#include "Controller.h"
#include <liboshima.h>

// ピン番号にボタンの名前を付ける
Button zensinButton(PIN_PD2);
Button koutenButton(PIN_PD3);

// IMを扱うための変数を作成
IM920SL im(Serial);

// 1回だけ実行される
void setup() {
  // IM920SLモジュールの通信を開始
  im.beginSerial();
}

// 繰り返し実行される
void loop() {
  // ボタンの状態を保持する変数を作成
  Controller controller;
  // 各ピンの状態を読み取り、controllerに格納
  if (zensinButton.isPressed()) {
    controller.motors[0] = MotorStateEnum::FORWARD;
  } else if (koutenButton.isPressed()) {
    controller.motors[0] = MotorStateEnum::REVERSE;
  } else {
    controller.motors[0] = MotorStateEnum::STOP;
  }
  // controllerを送信
  im.send(controller, ImSenderMode::CAREER_SENSE);
}