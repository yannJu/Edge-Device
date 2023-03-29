#include <BUTTON.h>
#include <LED.h>
//버튼을 한번 누르면 200ms 동안 소리나도록

// const int buzzer_pin = 9;
LED buzzer(9); // 부저와 LED 가 연결되어있으므로 LED로 불러와도 됨
BUTTON btn(2); // 버튼 2번 핀

void setup() {
  // put your setup code here, to run once:
  btn.setCallBack(buzzerPress);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 2초간 소리 키고 끄기
  // digitalWrite(buzzer_pin, HIGH);
  // delay(2000);
  
  // digitalWrite(buzzer_pin, LOW);
  // delay(2000);
  btn.check();
}

void buzzerPress() {
  // digitalWrite(buzzer_pin, HIGH);
  // delay(200);
  // digitalWrite(buzzer_pin, LOW);
  // LED와 BUZZER 가 연결되어있으므로 아래와 같이 LED 의 함수를 사용해도 됨
  buzzer.on();
  delay(200);
  buzzer.off();
}
