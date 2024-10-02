// 1回だけコンパイルされるようにする
#pragma once

// liboshimaのController.hをインクルード
#include <components/Controller.h>

// モーターの数を定義
#define NUM_MOTORS 1 + 2 // 1 = 前輪の旋回用モーター, 2 = 後輪のモーター
#define NUM_BUTTONS 0 // その他のボタンは使用しない
#define NUM_STICKS 0  // スティックは使用しない

// Controller型をControllerData型として扱えるようにする
using ControllerData = Controller<NUM_MOTORS, NUM_BUTTONS, NUM_STICKS>;