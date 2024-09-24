#include "controller/Controller.h" // コントローラーのデータ構造を使うためのヘッダファイル
#include <Arduino.h> // Arduinoで必要な基本的な機能を使うためのライブラリ
#include <components/ims/IM920SL.h> // 無線通信モジュール（IM920SL）を扱うためのライブラリ
#include <components/motors/NonSpeedAdjustable.h> // モーターを制御するためのライブラリ

// 無線通信に必要な変数を作成
SerialPort serialPort(Serial);
ImReceiver im(serialPort);

// 前輪のモーターを制御するオブジェクト
NonSpeedAdjustable frontWheel(PIN_PD2, PIN_PD3);
// 後輪L（左）のモーターを制御するオブジェクト
NonSpeedAdjustable rearWheelL(PIN_PD4, PIN_PD5);
// 後輪R（右）のモーターを制御するオブジェクト
NonSpeedAdjustable rearWheelR(PIN_PD6, PIN_PD7);

// Arduinoが動き始めたときに一度だけ実行される処理
void setup() {
  // 無線通信モジュールの初期化
  im.begin();
}

// メインの処理ループ（Arduinoが動作中は繰り返し実行される）
void loop() {
  // 無線通信でデータが受信されるまで待機
  // `im.available()` はデータが受信可能かどうかを確認する
  while (!im.available()) {
    delay(100); // 100ミリ秒待機してから再確認
  }

  // コントローラーのデータを受信するための変数
  Controller controller;
  // 無線通信でコントローラーの状態を受け取る
  im.receive(controller);

  // コントローラーの "前進" ボタンが押された場合
  if (controller.forward) {
    // 左右の後輪を前進させる
    rearWheelL.forward();
    rearWheelR.forward();
  }
  // コントローラーの "後退" ボタンが押された場合
  else if (controller.reverse) {
    // 左右の後輪を後退させる
    rearWheelL.reverse();
    rearWheelR.reverse();
  }
  // どちらのボタンも押されていない場合
  else {
    // 左右の後輪を止める
    rearWheelL.stop();
    rearWheelR.stop();
  }

  // コントローラーの "左" ボタンが押された場合
  if (controller.left) {
    // 前輪を前進させて左に曲がる（ステアリングの役割）
    frontWheel.forward();
  }
  // コントローラーの "右" ボタンが押された場合
  else if (controller.right) {
    // 前輪を後退させて右に曲がる（ステアリングの役割）
    frontWheel.reverse();
  }
  // 左右のボタンが押されていない場合
  else {
    // 前輪を止める
    frontWheel.stop();
  }
}
