#include <MiniCom.h>

MiniCom com;

int echoPin = 5;
int triggerPin = 6;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.setInterval(1000, check);
  com.print(0, "[[Ultrasonic]]");

  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check() {
  digitalWrite(triggerPin, HIGH);
  delay(100);
  digitalWrite(triggerPin, LOW);

  int dist = pulseIn(echoPin, HIGH) / 58;

  com.print(1, "Dist(cm) : ", dist);
}