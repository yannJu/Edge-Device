#include <LED.h>
#include <MsTimer2.h>

boolean led_val = LOW;
LED led(8);

void setup() {
  // put your setup code here, to run once:
  // 타이머2 인터럽트 설정 및 동작 시작

  MsTimer2::set(500, flash); // 500ms 인터럽트 주기 설정, flash() 함수 실행
  MsTimer2::start(); // timer2 동작 시작
}

void loop() {
  // put your main code here, to run repeatedly:
  // 하드웨어가 알아서 Interval(500ms) 간격으로 동작 -> 소프트웨어는 할 게 없음
}

void flash() {
  led_val = !led_val;
  led.setValue(led_val);
}
