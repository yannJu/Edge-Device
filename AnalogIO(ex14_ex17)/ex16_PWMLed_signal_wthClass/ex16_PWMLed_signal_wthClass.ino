#include <PWMLed.h>

const int var_pin = A0;
PWMLed led(9);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int analog_val, pwm_val;

  // ==========================
  // 서서히 9번 핀 LED 밝기를 밝힘
  // ==========================
  // for (pwm_val = 0; pwm_val < 256; pwm_val += 5) {
  //   led.setValue(pwm_val);
  //   delay(100);
  // }

  // led.off();
  // delay(2000);

  
  // ==========================
  // 가변 저항을 이용하여 LED 밝기 변경
  // ==========================
  analog_val = analogRead(var_pin); // 0-1023 값이 들어옴
  pwm_val = map(analog_val, 0, 1023, 255, 0); // 0-1023 값에서 255-0 으로 변환하여 직관적이게 만듦

  led.setValue(pwm_val);
}
