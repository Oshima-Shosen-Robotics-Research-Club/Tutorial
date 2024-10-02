// 他のファイルで実装された処理を流用するためにインクルード
#include <Arduino.h>
#include <components/ims/IM920SL.h>
#include <components/motors/NonSpeedAdjustable.h>
#include <controller/ControllerData.h>

// モーターを扱うための変数を作成
NonSpeedAdjustable zenrinSenkaiyouMotor(PIN_PD2, PIN_PD3);
NonSpeedAdjustable kourinMigiMotor(PIN_PD4, PIN_PD5);
NonSpeedAdjustable kourinHidariMotor(PIN_PD6, PIN_PD7);

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
    zenrinSenkaiyouMotor.forward();
  else if (data.motors[0].reverse)
    zenrinSenkaiyouMotor.reverse();
  else
    zenrinSenkaiyouMotor.stop();

  if (data.motors[1].forward)
    kourinMigiMotor.forward();
  else if (data.motors[1].reverse)
    kourinMigiMotor.reverse();
  else
    kourinMigiMotor.stop();

  if (data.motors[2].forward)
    kourinHidariMotor.forward();
  else if (data.motors[2].reverse)
    kourinHidariMotor.reverse();
  else
    kourinHidariMotor.stop();
}