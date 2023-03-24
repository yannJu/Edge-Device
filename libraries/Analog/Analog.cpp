#include "Analog.h"

Analog::Analog(int pin_num, int to_min, int to_max): pin_num(pin_num), from_min(0), from_max(1023), to_min(to_min), to_max(to_max) {}

void Analog::setRange(int to_min, int to_max) {
  this->to_min = to_min;
  this->to_max = to_max;
}

int Analog::read() {
  int value = analogRead(pin_num);
  return map(value, from_min, from_max, to_min, to_max);
}