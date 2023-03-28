#include <PIR.h>
#include <LED.h>
#include <MiniCom.h>
#include <Servo.h>

PIR pir(7);
LED led(9);

MiniCom com;
int timer_id = -1;
int state = 0; // 0 : timer off, 1 : timer on

Servo servo;
const int servo_pin = 3;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[PIR with Class]");

  pir.setCallBack(detect_on, detect_off);

  servo.attach(servo_pin);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
  pir.check();
}

void detect_on() {
  SimpleTimer &timer = com.getTimer();

  open();
  if (state == 0) {
    state = 1;
    timer_id = timer.setTimeout(5000, close);
  }
  else {
    timer.restartTimer(timer_id);
  }
}

void detect_off() {
  com.print(1, "Motion FIN_ . .");
  led.off();
}

void open() {
  com.print(1, "Motion Detected! . .");
  led.on();
  servo.write(90);
}

void close(){
  servo.write(0);
  timer_id = -1;
  state = 0;
}