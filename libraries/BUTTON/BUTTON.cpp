#include "BUTTON.h"

BUTTON::BUTTON(int pin_num) : pin_num(pin_num) {
  pinMode(pin_num, INPUT_PULLUP);
  callback = NULL;
}

void BUTTON::setCallBack(button_callback_t callback) {
  this->callback = callback; // 생성자에서만 pin_num(pin_num) 과 같이 초기화 가능
}

int BUTTON::read() {
  return !digitalRead(pin_num);
}

void BUTTON::check() {
  bool o_sw, n_sw;

  o_sw = read();
  delay(100);
  n_sw = read();

  if (o_sw == 0 && n_sw == 1) { // 이전 값이 OFF, 현재 값이 ON : 즉 Rising Edge 인 경우
    if (callback != NULL) callback();
  }
}