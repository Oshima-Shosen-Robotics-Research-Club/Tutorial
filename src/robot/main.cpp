// 他のファイルで実装された処理を流用するためにインクルード
#include <Arduino.h>
#include <components/ims/IM920SL.h>
#include <components/motors/NonSpeedAdjustable.h>
#include <controller/ControllerData.h>

// モーターを扱うための変数を作成
NonSpeedAdjustable motor(PIN_PD2, PIN_PD3);

// IMを扱うための変数を作成
SerialPort serial(Serial);
IM920SL im(serial);

// 1回だけ実行される
void setup() {
  // IM920SLモジュールの通信を開始
  im.begin();
}

// 繰り返し実行される
void loop() {
  // ボタンの状態を保持する変数を作成
  ControllerData data;
  // dataを受信
  im.receive(data);

  // dataを元にモーターを制御
  if (data.motors[0].forward)
    motor.forward();
  else if (data.motors[0].reverse)
    motor.reverse();
  else
    motor.stop();
}