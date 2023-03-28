#include <MiniCom.h>

MiniCom com;
const int lm35_pin = A1;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.setInterval(2000, check);
  com.print(0, "[[LM35]]");
  com.print(1, "Preparing . . .");
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check() {
  int value = analogRead(lm35_pin);
  float ftp = (float)value / 1024.0 * 5.0; // 온도센서 전압값

  ftp = ftp * 100.0 + 0.5;

  // dht11 은 24.80 나옴
  com.print(1, "T : ", ftp);
}
