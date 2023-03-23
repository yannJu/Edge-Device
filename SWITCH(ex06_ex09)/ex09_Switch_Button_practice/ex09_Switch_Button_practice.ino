#include <LED.h>
#include <BUTTON.h>

BUTTON btn(2);
LED leds[4] = {LED(8), LED(9), LED(10), LED(11)};
LED pin_7th = LED(7);         

int out_no = 0;
unsigned long time = 0;

void move_led() {
  for (int n = 0; n < 4; n++) {
    leds[n].setValue(n == out_no);
  }
  // delay(1000);
  ++out_no %= 4;
}
  
void toggle() {
  pin_7th.toggle();
}

void setup() {
  // put your setup code here, to run once:
  btn.setCallBack(toggle);
  time = millis(); // 시작 시간 측정
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // 1초 간격으로 LED 점등 이동 
  // move_led();/
  
  // 2번 핀에 연결된 버튼을 누르면
  // 7번 핀에 연결된 LED 토글
  // btn.check();

  // ===========================
  // delay() 를 쓰면 비동기식으로 동작할 수 없음
  //    → millis 를 사용
  //    → timer 모듈을 이용하자, btn 은 전위차, led는 시간차 이기 때문에 똑같음
  //    → 1초가 지나는 것을 계속 check 
  // ===========================
  btn.check();
  unsigned long current_time = millis();
  if (current_time - time >= 1000) {
    move_led();
    time = current_time;
  }

}
