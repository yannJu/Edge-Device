#include "Ultra.h"

Ultra::Ultra(int echo, int trigger) : echo(echo), trigger(trigger) {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  on_f = NULL;
  off_f = NULL;
  state = false;
}

int Ultra::getDistance() {
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);

  int dist = pulseIn(echo, HIGH) / 58;

  return dist;
}
void Ultra::setThreshold(int t, ultra_callback_t on_f, ultra_callback_t off_f) {
  threshold = t;
  this->on_f = on_f;
  this->off_f = off_f;
}

int Ultra::run() {
  int distance = getDistance();

  if (!state && distance <= threshold) { // 기준거리에 진입해 있으면서 문이 닫혀있는 경우
    state = true; // 문열기
    if (on_f) on_f();
  }
  else if (state && (distance < 0 || distance > threshold)) { // 문이 열려있으면서 기준거리에서 벗어난 경우
    state = false;
    if (off_f) off_f();
  }

  if (distance == 0 || distance > threshold) return 0; // 어떤 것도 감지되지 않은 경우

  return distance; // 감지된 경우 거리 return
}