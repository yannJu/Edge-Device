#include <Servo.h>
#include <MiniCom.h>
#include <Analog.h>

Analog sensor(A0, 180, 0);

MiniCom com;

Servo myServo;
const int servo_pin = 5;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[Servo Test- -]]");

  myServo.attach(servo_pin);

  com.setInterval(1000, check);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check() {
  int angle = sensor.read();
  myServo.write(angle);
  com.print(1, "Angle : ", angle);
}