#include <Analog.h>
#include <PWMLed.h>

Analog sensor(A0, 255, 0); // A0번 핀에 있는 센서, 255-0으로 반환
PWMLed led(9);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int pwm_val = sensor.read(); // 센서에서 아날로그 값을 읽어와 255-0 으로 변환받음
  led.setValue(pwm_val); // 읽어온 값을 PWMLed에 set
}
