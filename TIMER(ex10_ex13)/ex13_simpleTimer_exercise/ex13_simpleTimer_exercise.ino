#include <LED.h>
#include <BUTTON.h>
#include <SimpleTimer.h>

LED led = LED(8);
BUTTON btn = BUTTON(2);
SimpleTimer timer = SimpleTimer();

int click_cnt = 0;
int intervals[3] = {1000, 600, 300};
int timerId = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  btn.setCallBack(settingInterval);
  timerId = timer.setInterval(intervals[click_cnt], blinkLed);
}

void loop() {
  // put your main code here, to run repeatedly:
  // default 1초 간격으로 led 8번 blink
  // 2번 연결된 버튼 클릭시 간격을 0.6초 간격으로 변경
  // 다시 한번 더 누르면 0.3초 간격으로
  // 다시 누르면 default 로 돌아옴
  btn.check();
  timer.run();
}

void blinkLed() {
  led.toggle();
}

void settingInterval() {
  ++click_cnt %= 3;
  Serial.println(intervals[click_cnt]);

  timer.deleteTimer(timerId);
  timerId = timer.setInterval(intervals[click_cnt], blinkLed);
}
