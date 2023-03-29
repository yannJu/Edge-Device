#include <BtMiniCom.h>
#include <Car.h>

void receiveMsg(String msg);
BtMiniCom btCom(13, 12, receiveMsg);

int in1Pin = 6; // 좌측 바퀴 in1
int in2Pin = 7; // 좌측 바퀴 in2
int ENAPin = 5; // 좌측 바퀴 GND

int in3Pin = 8; // 우측 바퀴 in1
int in4Pin = 9; // 우측 바퀴 in2
int ENBPin = 10; // 좌측 바퀴 GND

Car car(in1Pin, in2Pin, ENAPin, in3Pin, in4Pin, ENBPin);

void setup() {
  // put your setup code here, to run once:
  btCom.init();
  car.stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  btCom.run();
}

void receiveMsg(String msg) {
  String result = "ok : " + msg;

  if (msg == "forward") {
    car.setSpeed(250);
    car.forward();
  }
  else if (msg == "backward") {
    car.setSpeed(200);
    car.backward();
  }
  else if (msg == "turnLeft") {
    car.setSpeed(150);
    car.turnLeft();
  }
  else if (msg == "turnRight") {
    car.setSpeed(150);
    car.turnRight();
  }
  else if (msg == "stop") {
    car.stop();
  }
  else {
    result = "bad Command : " + msg;
  }

  btCom.send(result);
}