const int led_pin = 9; //PWM 지원하는 pin

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, 0); // 0을 줌으로써 OFF를 의미
}

void loop() {
  // put your main code here, to run repeatedly:
  int pwm_val;

  for (pwm_val = 0; pwm_val < 256; pwm_val += 5) {
    analogWrite(led_pin, pwm_val);
    delay(100); // 0.1초마다 서서히 밝아짐
  }

  digitalWrite(led_pin, 0);
  delay(2000);
}
