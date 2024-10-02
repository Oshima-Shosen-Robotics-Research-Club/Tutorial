// 他のファイルで実装された処理を流用するためにインクルード
#include "ControllerData.h"
#include <Arduino.h>
#include <components/ims/IM920SL.h>

// ピン番号にボタンの名前を付ける
#define ZENTEN_BUTTON PIN_PD2
#define KOUTEN_BUTTON PIN_PD3

// IMを扱うための変数を作成
SerialPort serial(Serial);
IM920SL im(serial);

// 1回だけ実行される
void setup() {
  // 各ピンをボタンとして使えるように設定
  pinMode(ZENTEN_BUTTON, INPUT_PULLUP);
  pinMode(KOUTEN_BUTTON, INPUT_PULLUP);
  // IM920SLモジュールの通信を開始
  im.begin();
}

// 繰り返し実行される
void loop() {
  // ボタンの状態を保持する変数を作成
  ControllerData data;
  // 各ピンの状態を読み取り、dataに格納
  data.motors[0].forward = !digitalRead(ZENTEN_BUTTON);
  data.motors[0].reverse = !digitalRead(KOUTEN_BUTTON);
  // dataを送信
  im.send(data);
}