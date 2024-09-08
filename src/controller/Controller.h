#ifndef CONTROLLER_H
#define CONTROLLER_H

// コントローラーの構造体
struct Controller {
  unsigned int forward : 1; // 前進
  unsigned int reverse : 1; // 後退
  unsigned int left : 1;    // 左
  unsigned int right : 1;   // 右
};

#endif // CONTROLLER_H