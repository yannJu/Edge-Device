#include <LED.h>
#include <TimerOne.h>

boolean led_val = LOW;
LED led(9);

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(500000); // us 단위/이기 때문에 500000 : 정밀한 설정 가능
  Timer1.attachInterrupt(flash);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Timer1 을 동작시키기 때문에 하드웨어가 동작 : 소프트웨어적 처리가 없음
}

void flash() {
  led_val = !led_val;
  led.setValue(led_val);
}