#include "Controller.h" // コントローラーのデータ構造を定義したヘッダファイルをインクルード
#include <Arduino.h> // Arduinoで必要な基本的な機能を使うためのライブラリ
#include <components/ims/IM920SL.h> // 無線通信モジュール（IM920SL）を扱うためのライブラリ

// コントローラーの入力を受け取るためのピン定義
// それぞれの動きに対応するピン番号を設定
#define FORWARD_PIN PIN_PD4 // 前進用のピン
#define REVERSE_PIN PIN_PD5 // 後退用のピン
#define LEFT_PIN PIN_PD6    // 左旋回用のピン
#define RIGHT_PIN PIN_PD7   // 右旋回用のピン

// 無線通信に必要な変数を作成
SerialPort serialPort(Serial);
ImSender im(serialPort);

// Arduinoが動き始めたときに一度だけ実行される処理
void setup() {
  // ピンを入力モードで、内部プルアップ抵抗を使って設定
  // INPUT_PULLUP により、ピンが接続されていないときに HIGH になる
  pinMode(FORWARD_PIN, INPUT_PULLUP);
  pinMode(REVERSE_PIN, INPUT_PULLUP);
  pinMode(LEFT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);

  // 無線通信モジュールを初期化
  im.begin();
}

// メインの処理ループ（Arduinoが動作中は繰り返し実行される）
void loop() {
  // コントローラーの状態を保存するための変数
  Controller controller;

  // 各ピンの状態を読み取る（ボタンが押されていれば LOW になるため、反転させて 1/0 を設定）
  controller.forward = !digitalRead(FORWARD_PIN); // 前進ボタンが押されていれば 1
  controller.reverse = !digitalRead(REVERSE_PIN); // 後退ボタンが押されていれば 1
  controller.left = !digitalRead(LEFT_PIN); // 左ボタンが押されていれば 1
  controller.right = !digitalRead(RIGHT_PIN); // 右ボタンが押されていれば 1

  // コントローラーの状態を無線通信で送信
  im.send(controller);

  // 100ミリ秒待機してから次のループへ
  delay(100);
}
