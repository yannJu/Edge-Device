#pragma once
#include <Arduino.h>

class Ultra {
protected:
  int echo;
  int trigger;
public:
  Ultra(int echo, int trigger);
  int getDistance();
};