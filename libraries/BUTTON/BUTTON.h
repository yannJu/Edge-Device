#pragma once
#include <Arduino.h>

typedef void (*button_callback_t)();

class BUTTON {
protected:
  int pin_num;
  button_callback_t callback;
public:
  BUTTON(int pin_num);
  void setCallBack(button_callback_t callback);
  int read();
  void check();
};