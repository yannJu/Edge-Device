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

    // ====================
    // 혹은 toggle 을 이용하여 아래와 같이도 구현 가능
    //    단, toggle 사용시 for문 밖의 두줄은 사용 안함
    // ====================
    // leds[n].toggle();
    // delay(1000);
    // leds[n].toggle();
    
    // ====================
    // 혹은 setValue 를 이용하여 구현 가능
    // ====================
    // leds[n].setValue(n == out_no);
  }

  ++out_no %= 4;
  delay(1000);

  // 한번 점열 돌면 3번 깜빡이기
  if (out_no == 0) {
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 4; i++) {
        leds[i].on();
      }
      delay(500);
      for (int i = 0; i < 4; i++) {
        leds[i].off();
      }
      delay(500);
    }
  }
}
