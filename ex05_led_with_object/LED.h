#pragma once // 한번만 include 해라 ~ 
#include <Arduino.h>

class LED {
protected:
  int pin_num; // 상속을 대비하여 protected
public:
  LED(int pin_num); // 생성자, 원형

  void on();
  void off();
  void setValue(int value);
  int toggle();
};