#include <MiniCom.h>
#include <Analog.h>
#include <LED.h>

LED led(7); // red light

MiniCom com;
Analog cds(A0, 0, 100);

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.setInterval(100, check);
  com.print(0, "[[CdS Test]]");
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check() {
  int value = cds.read();
  com.print(1, "Illu : ", value);

  led.setValue(value > 80);
}
