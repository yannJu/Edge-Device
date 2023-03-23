#include <LED.h>
#include <BUTTON.h>

BUTTON btn(2);
LED leds[4] = {LED(8), LED(9), LED(10), LED(11)};
int out_no = -1;

void move_led() {
  ++out_no %= 4;
  Serial.println(out_no);
  for (int n = 0; n < 4; n++) {
    leds[n].setValue(n == out_no);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  btn.setCallBack(move_led);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn.check();
}
