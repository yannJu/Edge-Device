#include <BUTTON.h>
#include <MiniCom.h>

MiniCom com;
BUTTON btn(2);

int relay_pin = 4;
boolean relay_out = LOW;

int timer_id = -1;

void blink() {
  relay_out = !relay_out;
  digitalWrite(relay_pin, relay_out);
}

void check() {
  if (timer_id < 0) {
    timer_id = com.setInterval(500, blink);
    com.print("1", "Blinking - ");
  }
  else {
    SimpleTimer &timer = com.getTimer();
    timer.deleteTimer(timer_id);
    timer_id = -1;
    
    // 전등이 켜진 상태로 버튼을 다시 누르게 되면 계속 전등이 켜져있으므로 상태를 강제로 변화해주어야 함.
    relay_out = false;
    digitalWrite(relay_pin, relay_out);

    com.print(1, ". . .");
  }
}

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[Relay Ex !!]]");

  btn.setCallBack(check);
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn.check();    
  com.run();            
}
