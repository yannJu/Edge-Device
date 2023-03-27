#include <MiniCom.h>
#include <LED.h>

//1초 간격으로 LED를 blink
//현재 상태를 LCD 로 출력해보기
MiniCom com;
LED led(8);

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[MiniCom-]]");
  com.setInterval(1000, check); // 1초 마다 check 함수 호출
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run(); // timer 를 계속 확인
}

void check() {
  int on = led.toggle();

  if (on) com.print(1, "LED is /ON/");
  else com.print(1, "LED is /OFF/");
}
