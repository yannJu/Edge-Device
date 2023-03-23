#include <SimpleTimer.h>

SimpleTimer timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  timer.setInterval(1000, repeatMe); // 1초 마다 repeatMe 실행
}

void loop() {
  // put your main code here, to run repeatedly:
  timer.run(); // 꼭 해주어야 함 !!
}

void repeatMe() {
  Serial.print("Uptime (s) : ");
  Serial.println(millis() / 1000);
}
