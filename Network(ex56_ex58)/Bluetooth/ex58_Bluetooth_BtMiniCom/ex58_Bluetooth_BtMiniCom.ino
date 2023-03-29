#include <BtMiniCom.h>
#include <LED.h>
#include <Servo.h>

void receiveMsg(String msg);

int count = 0;
BtMiniCom btcom(13, 12, receiveMsg);

LED led(9);

Servo servo;
const int servo_pin = 3;

void setup() {
  // put your setup code here, to run once:
  btcom.init();
  btcom.print(0, "[[Bluetooth-]]");

  servo.attach(servo_pin);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  btcom.run();
}

void receiveMsg(String msg) {
  char buf[17];
  sprintf(buf, "%d)%s", ++count, msg.c_str());

  device_control(msg);

  btcom.print(1, buf);
  btcom.send("input val : " + msg);
}

void device_control(String msg) {
  if (msg.equals("on")) led.on();
  else if (msg.equals("off")) led.off();
  else if (msg.equals("open")) servo.write(90);
  else if (msg.equals("close")) servo.write(0);
}