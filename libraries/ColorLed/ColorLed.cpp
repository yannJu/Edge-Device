#include "ColorLed.h"

ColorLed::ColorLed(int red, int green, int blue) : red(red), green(green), blue(blue) {}
void ColorLed::rgb(int r, int g, int b) {
  red.setValue(r);
  green.setValue(g);
  blue.setValue(b);

  // Serial.println("[RED] : %s [Green] : %s [Blue] : %s", r, g, b);
}
void ColorLed::off(int delay_time = 0) {
  rgb(0, 0, 0);
  if (delay_time > 0) delay(delay_time);
}
void ColorLed::random() {
  int r = ::random(256);
  int g = ::random(256);
  int b = ::random(256);

  rgb(r, g, b);
}