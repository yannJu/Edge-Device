#include <BUTTON.h>
#include <Melody.h>
#include <MiniCom.h>
#include "pirates.h"

MiniCom com;
Melody melody(9, notes, durations, length);
BUTTON btn(2);

void setup() {
  // put your setup code here, to run once:
  com.init();
  btn.setCallBack(btnPressed);
  melody.play();
  com.print(0, "<< PLAY ♪ >>");
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
  melody.run();
  btn.check();
}

void btnPressed() {
  boolean bplay = melody.toggle(true);
  if (bplay) {
    com.print(0, "<< PLAY ♪ >>");
  }
  else {
    com.print(0, "<< PAUSE ● >>");
  }
}
