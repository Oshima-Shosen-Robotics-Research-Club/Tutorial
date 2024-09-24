#pragma once

// コントローラーの構造体
struct Controller {
  unsigned int forward : 1; // 前進
  unsigned int reverse : 1; // 後退
  unsigned int left : 1;    // 左
  unsigned int right : 1;   // 右
};
