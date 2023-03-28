#include <MiniCom.h>
#include <Analog.h>
#include <BUTTON.h>
#include <Servo.h>

Servo servo;
int servo_pin = 3;

MiniCom com;
Analog x(A0, 180, 0);
Analog y(A1);
Analog z(A2);

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.setInterval(100, check); // 0.1초마다 값을 확인
  com.print(0, "[[JoyStick]]");

  servo.attach(servo_pin);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check() {
  int dx, dy;
  boolean sw;

  dx = x.read();
  dy = y.read();
  sw = z.read();

  // 조이스틱 값으로 servo 모터 조정
  servo.write(dx);

  char buf[17];
  sprintf(buf, "/%3d/ /%3d/ [%d]", dx, dy, sw);
  com.print(1, buf);
}
