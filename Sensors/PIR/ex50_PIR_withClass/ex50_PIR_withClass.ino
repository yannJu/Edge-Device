#include <PIR.h>
#include <LED.h>
#include <MiniCom.h>
#include <Servo.h>

PIR pir(7);
LED led(9);

MiniCom com;
int timer_id = -1;

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
  
  com.print(1, "Motion Detected! . .");
  led.on();

  open();
  timer_id = timer.setTimeout(3000, close);
}

void detect_off() {
  com.print(1, "Motion FIN_ . .");
  led.off();
}

void open() {
  servo.write(90);
}

void close(){
  servo.write(0);
  timer_id = -1;
}