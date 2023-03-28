#pragma once
#include <Arduino.h>

typedef void (*pir_callback_t)();

class PIR {
protected:
  int pin;
  int state;
  pir_callback_t on_f;
  pir_callback_t off_f;
public:
  PIR(int pin);
  void setCallBack(pir_callback_t on_f, pir_callback_t off_f);
  void check();
};