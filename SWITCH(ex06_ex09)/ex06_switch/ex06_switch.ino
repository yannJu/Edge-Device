#include <LED.h>

const int pu_sw_pin = 2;
LED blue_led(4);

void setup() {
  // put your setup code here, to run once:
  pinMode(pu_sw_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean pu_sw;

  // default 로 switch 를 누르지 않으면 I/O 에 high
  //    즉 pu_sw = 1
  // pu_sw 를 setValue 로 하면 버튼을 누르지 않을 때 LED = High 
  // 따라서 '!' 를 이용하여 풀다운 방식과 같이 구현
  pu_sw = digitalRead(pu_sw_pin);
  blue_led.setValue(!pu_sw);
}
