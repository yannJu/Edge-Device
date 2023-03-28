#include "PIR.h"

PIR::PIR(int pin) : pin(pin) {
  pinMode(pin, INPUT);
  state = LOW;
  on_f = NULL;
  off_f = NULL;
} 

void PIR::setCallBack(pir_callback_t on_f, pir_callback_t off_f) {
  this->on_f = on_f;
  this->off_f = off_f;
}

void PIR::check() {
  int val = digitalRead(pin);

  if (val == HIGH) {
    if (state == LOW) { // 상승엣지
      state = HIGH;
      if(on_f) on_f();
    }
  }
  else {
    if (state == HIGH) { // 하강엣지
      state = LOW;
      if (off_f) off_f();
    }
  }
}