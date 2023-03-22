const int pu_led_pin = 13; //pull up pin
const int pd_led_pin = 4; //pull down pin

void setup() {
  // put your setup code here, to run once:
  pinMode(pu_led_pin, OUTPUT);
  pinMode(pd_led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 일정시간 간격으로 의미를 준다 -> blink? 
  // pu_led_pin 을 13으로 바꾸면 pull down 일때 아두이노 불이 들어옴
  //    내부구성이 pull down 이기 때문!
  digitalWrite(pu_led_pin, HIGH);
  digitalWrite(pd_led_pin, HIGH);

  delay(1000);

  digitalWrite(pu_led_pin, LOW);
  digitalWrite(pd_led_pin, LOW);

  delay(1000);
}
