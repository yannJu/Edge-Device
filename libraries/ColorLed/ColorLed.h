#pragma once

// #include <Arduino.h> // 이미 PWMLed.h 에서 불러오기 때문에 안불러와도 됌
#include <PWMLed.h>

class ColorLed {
protected:
  PWMLed red;
  PWMLed green;
  PWMLed blue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ;
public:
  ColorLed(int red, int green, int blue);
  void rgb(int r, int g, int b);
  void off(int delay_time = 0);
  void random();
};