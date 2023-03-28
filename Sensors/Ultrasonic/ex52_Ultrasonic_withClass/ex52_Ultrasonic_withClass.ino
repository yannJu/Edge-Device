#include <Ultra.h>
#include <MiniCom.h>

MiniCom com;
Ultra ultra(5, 6);

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.setInterval(1000, check);
  com.print(0, "[Ultra with Class]");
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check() {
  int distance = ultra.getDistance();

  com.print(1, "Distance : ", distance);
}