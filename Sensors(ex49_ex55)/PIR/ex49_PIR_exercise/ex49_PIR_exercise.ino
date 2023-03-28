#include <MiniCom.h>
#include <LED.h>

LED led(9);
MiniCom com;

int pir_pin = 7;
int pir_state = LOW;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[PIR]]");
  pinMode(pir_state, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
  val = digitalRead(pir_pin);

  if (val == LOW) {
    if (pir_state == HIGH) {
      com.print(1, "Motion_FIN . .");
      pir_state = LOW;
    }
  }
  else {
    if (pir_state == LOW) {
      com.print(1, "Motion Detected !");
      pir_state = HIGH;
    }
  }

  led.setValue(val);
}
