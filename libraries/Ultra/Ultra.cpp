#include "Ultra.h"

Ultra::Ultra(int echo, int trigger) : echo(echo), trigger(trigger) {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
}

int Ultra::getDistance() {
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);

  int dist = pulseIn(echo, HIGH) / 58;

  return dist;
}