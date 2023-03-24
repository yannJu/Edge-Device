#include "PWMLed.h"

PWMLed::PWMLed(int pin_num, int value): LED(pin_num), value(value) {
  analogWrite(pin_num, value); // 크게 의미없음, setup() 이전엔 어떠한 입출력도 효과가 없음 ㅎ .ㅎ ...
}

void PWMLed::setValue(int val) {
  this->value = val;
  analogWrite(pin_num, val);
}