#include <LED.h>

#define OFF 0
#define ON 1

const int in_pu_sw_pin = 2;
// LED led(8); // Green
LED leds[4] = {LED(8), LED(9), LED(10), LED(11)};
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(in_pu_sw_pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean o_sw, n_sw;

  o_sw = !digitalRead(in_pu_sw_pin);
  delay(100);
  n_sw = !digitalRead(in_pu_sw_pin);

  if (o_sw == OFF && n_sw == ON) {
    Serial.println(count);

    for (int n = 0; n < 4; n++) {
      leds[n].setValue(n == count);
    }
    
    ++count %= 4;
  }
}
