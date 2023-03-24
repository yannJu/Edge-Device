#include <MiniCom.h>
#include <Analog.h>
#include <PWMLed.h>

// 1초에 10번 측정
// 가변저항 값을 측정
// LED 밝기를 조정
// 밝기 값을 LCD 에 출력
MiniCom com;
PWMLed led(9, 0);
Analog sensor(A0, 255, 0);

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[LED Val-]]");
  com.setInterval(100, check); //1초에 10번 측정
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check() {
  int val;

  val = sensor.read(); // 가변저항 값을 측정
  led.setValue(val); // LED 밝기 조정
  
  com.print(1, "Value : ", val);
}