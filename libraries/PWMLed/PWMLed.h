#pragma once

#include <Arduino.h>
#include <LED.h>

class PWMLed: public LED {
protected:
  int value; // 아날로그 값

public:
  PWMLed(int pin_num, int value = 0);
  void setValue(int val);
};