#include "LED.h" // 먼저 같은 (현재) 디렉토리에서 찾고, 없으면 지정한 라이브러리에서 찾아라!

LED::LED(int pin_num) : pin_num(pin_num) {
  // this->pin_num = pin_num
  pinMode(pin_num, OUTPUT);
}

void LED::on() {
  digitalWrite(pin_num, HIGH);
}

void LED::off() {
  digitalWrite(pin_num, LOW);
}

void LED::setValue(int val) {
  digitalWrite(pin_num, val);
}

int LED::toggle() {
  int v = !digitalRead(pin_num);
  digitalWrite(pin_num, v);

  return v; // toggle 된 value 값을 return
}