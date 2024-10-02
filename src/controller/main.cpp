// 他のファイルで実装された処理を流用するためにインクルード
#include "ControllerData.h"
#include <Arduino.h>
#include <components/ims/IM920SL.h>

// ピン番号にボタンの名前を付ける
#define ZENRIN_SEITEN_BUTTON PIN_PD2
#define ZENRIN_KOUTEN_BUTTON PIN_PD3
#define KOURIN_MIGI_SEITEN_BUTTON PIN_PD4
#define KOURIN_MIGI_KOUTEN_BUTTON PIN_PD5
#define KOURIN_HIDARI_SEITEN_BUTTON PIN_PD6
#define KOURIN_HIDARI_KOUTEN_BUTTON PIN_PD7

// IMを扱うための変数を作成
SerialPort serial(Serial);
IM920SL im(serial);

// 1回だけ実行される
void setup() {
  // 各ピンをボタンとして使えるように設定
  pinMode(ZENRIN_SEITEN_BUTTON, INPUT_PULLUP);
  pinMode(ZENRIN_KOUTEN_BUTTON, INPUT_PULLUP);
  pinMode(KOURIN_MIGI_SEITEN_BUTTON, INPUT_PULLUP);
  pinMode(KOURIN_MIGI_KOUTEN_BUTTON, INPUT_PULLUP);
  pinMode(KOURIN_HIDARI_SEITEN_BUTTON, INPUT_PULLUP);
  pinMode(KOURIN_HIDARI_KOUTEN_BUTTON, INPUT_PULLUP);
  // IM920SLモジュールの通信を開始
  im.begin();
}

// 繰り返し実行される
void loop() {
  // ボタンの状態を保持する変数を作成
  ControllerData data;
  // 各ピンの状態を読み取り、dataに格納
  data.motors[0].forward = !digitalRead(ZENRIN_SEITEN_BUTTON);
  data.motors[0].reverse = !digitalRead(ZENRIN_KOUTEN_BUTTON);
  data.motors[1].forward = !digitalRead(KOURIN_MIGI_SEITEN_BUTTON);
  data.motors[1].reverse = !digitalRead(KOURIN_MIGI_KOUTEN_BUTTON);
  data.motors[2].forward = !digitalRead(KOURIN_HIDARI_SEITEN_BUTTON);
  data.motors[2].reverse = !digitalRead(KOURIN_HIDARI_KOUTEN_BUTTON);
  // dataを送信
  im.send(data);
}