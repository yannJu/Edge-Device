#include "LED.h"

LED leds[4] = {LED(3), LED(4), LED(5), LED(6)};
int out_no = 0; // 출력할 값 출력 순서 번호(0-3)
void setup() {
  // put your setup code here, to run once:
  // 클래스 정의 함으로서 setup 할 구문이 없음
}

void loop() {
  // put your main code here, to run repeatedly:
  int n;

  for (n = 0; n < 4; n++) {
    if (n == out_no) leds[n].on();
    else leds[n].off();
    // 혹은 toggle 을 이용하여 아래와 같이도 구현 가능
    // toggle 사용시 for문 밖의 두줄은 사용 안함
    // leds[n].toggle();
    // delay(1000);
    // leds[n].toggle();
  }

  ++out_no %= 4;
  delay(1000);
}
