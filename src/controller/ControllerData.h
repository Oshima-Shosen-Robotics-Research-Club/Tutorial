// 1回だけコンパイルされるようにする
#pragma once

// liboshimaのController.hをインクルード
#include <components/Controller.h>

// モーターの数を定義
#define NUM_MOTORS 1  // モーターは1つ
#define NUM_BUTTONS 0 // モーター以外にボタンは使用しない
#define NUM_STICKS 0  // スティックは使用しない

// Controller型をControllerData型として扱えるようにする
#define ControllerData Controller<NUM_MOTORS, NUM_BUTTONS, NUM_STICKS>