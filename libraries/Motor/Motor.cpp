#include "Motor.h"

Motor::Motor(int in1, int in2, int en) : in1(in1), in2(in2), en(en) {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en, OUTPUT);

  analogWrite(en, 0);
}

void Motor::forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void Motor::backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void Motor::stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  analogWrite(en, 0);
}