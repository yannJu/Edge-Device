#include <Servo.h>
#include <MiniCom.h>

MiniCom com;
Servo myServo;
const int servo_pin = 5;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[Servo Test- -]]");

  myServo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  move_angle(0, 1000);
  move_angle(90, 1000);
  move_angle(180, 1000);
  move_angle(90, 1000);
  move_angle(0, 1000);
}

void move_angle(int angle, int delay_time) {
  myServo.write(angle);
  com.print(1, "Angle : ", angle);
  delay(delay_time);
}