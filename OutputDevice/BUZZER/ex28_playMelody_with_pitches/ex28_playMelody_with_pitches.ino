#include "pirates.h"

const int speaker_pin(9);

void setup() {
  // put your setup code here, to run once:

}
void loop() {
  // put your main code here, to run repeatedly:
  int m, d, dd;

  for(m = 0; m < length; m++) {
    d = 1000 / durations[m];
    dd = d * 1.3;

    tone(speaker_pin, notes[m], d);
    delay(dd);
  }

  delay(1000);
}
