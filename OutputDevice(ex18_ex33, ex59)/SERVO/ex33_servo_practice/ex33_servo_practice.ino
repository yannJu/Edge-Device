#include <BUTTON.h>
#include <LED.h>
#include <Servo.h>
#include <MiniCom.h>
#include <SimpleTimer.h>

// 센서 ================
BUTTON btn(2);
LED led(9);
Servo servo;
MiniCom com;
// =====================

int servo_pin = 5;
int timer_id = -1;
int state = 0; // 0:Close

void setup() {
  // put your setup code here, to run once:
  servo.attach(servo_pin);
  servo.write(state);
  
  //com Init
  com.init();
  com.print(0, "[[Servo App]]");
  com.print(1, "[Door]is/CLOSE/");

  btn.setCallBack(check);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
  btn.check();
}

void check() {
  SimpleTimer &timer = com.getTimer();
  if (state == 0) {
    //문 열기
    openDoor();
    timer_id = timer.setTimeout(3000, closeDoor);
  }
  else {
    timer.restartTimer(timer_id);
  }
}

void openDoor() {  
  //짧게 삐- 소리 내기
  led.on();
  delay(100);
  led.off();

  //상태 변경
  state = 1;
  com.print(1, "[Door]is/OPEN/");
  servo.write(90);
}

void closeDoor(){
  //문 닫기
  com.print(1, "[Door]is/CLOSE/");
  servo.write(0);
  state = 0;
  timer_id = -1;
}