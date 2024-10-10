// 他のファイルで実装された処理を流用するためにインクルード
#include <Arduino.h>
#include <controller/Controller.h>
#include <liboshima.h>

// モーターを扱うための変数を作成
// motor=(PIN_PD2, PIN_PD3);と覚えると良い
NonSpeedAdjustable motor(PIN_PD2, PIN_PD3);

// IMを扱うための変数を作成
IM920SL im(Serial);

// 1回だけ実行される
void setup() {
  // IM920SLモジュールの通信を開始
  im.begin();
}

// 繰り返し実行される
void loop() {
  // ボタンの状態を保持する変数を作成
  Controller controller;
  // controllerを受信
  im.receive(controller);

  // controllerを元にモーターを制御
  switch (controller.motors[0]) {
  case MotorStateEnum::Forward:
    motor.forward();
    break;
  case MotorStateEnum::Reverse:
    motor.reverse();
    break;
  case MotorStateEnum::Stop:
    motor.stop();
    break;
  }
}