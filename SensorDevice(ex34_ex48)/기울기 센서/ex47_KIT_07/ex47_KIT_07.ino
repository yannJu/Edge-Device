#include <LED.h>

LED led(9);

const int tilt_pin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(tilt_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool t_sw;

  t_sw = digitalRead(tilt_pin);
  led.setValue(t_sw);
}
