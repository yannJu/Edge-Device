#pragma once

#include <Arduino.h>

class Motor {
protected:
  int in1;
  int in2;
  int en;

public:
  Motor(int in1, int in2, int en);

  void forward();
  void backward();
  void setSpeed(int speed) {
    analogWrite(en, speed);
  }
  void stop();
};