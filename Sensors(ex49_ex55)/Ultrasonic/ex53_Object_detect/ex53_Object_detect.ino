#include <MiniCom.h>
#include <Ultra.h>
#include <LED.h>
#include <Servo.h>

MiniCom com;
Ultra ultra(5, 6);

LED buzzer(9);

Servo servo;
int servo_pin = 3;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[Object Detect]");

  ultra.setThreshold(30, notice_in, notice_out);

  servo.attach(servo_pin);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
  ultra.run();
}

void notice_in() {
  com.print(1, "Object /Detect/!");
  open();
}

void notice_out() {
  com.print(1, "No Object . .");
  close();
}

void open() {
  buzzer.on();
  delay(100);

  servo.write(90);
}

void close() {
  buzzer.off();
  servo.write(0);
}
