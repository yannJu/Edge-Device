#include <LED.h>
#include <MiniCom.h>
#include <BUTTON.h>

MiniCom com;

BUTTON btn(2);

LED led(9);
const int tilt_pin = 4;

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(tilt_pin, INPUT);
  com.init();
  com.print(0, "[[Tilt]]");

  btn.setCallBack(btnClick);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool t_sw1, t_sw2;

  btn.check();
  com.print(1, "Count is ", count);

  t_sw1 = digitalRead(tilt_pin);
  delay(200);
  t_sw2 = digitalRead(tilt_pin);

  if (t_sw1 == LOW && t_sw2 == HIGH) {
    count += 1;
    led.toggle();
  }
}

void btnClick() {
  count = 0;
}