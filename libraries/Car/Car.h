#pragma once

#include <Arduino.h>
#include <Motor.h>

class Car {
protected:
  Motor left;
  Motor right;

public:
  Car(int in1, int in2, int ena, int in3, int in4, int enb);

  void forward();
  void backward();
  void turnLeft();
  void turnRight();
  void setSpeed(int speed);
  void stop();
};