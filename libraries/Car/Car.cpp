Car::Car(int in1, int in2, int ena, int in3, int in4, int enb) : in1(in1), in2(in2), ena(ena), in3(in3), in4(in4), enb(enb) {
  left(in1, in2, ena);
  right(in3, in4, enb);
}

void Car::forward() {
  left.forward();
  right.forward();
}
void Car::backward() {
  left.backward();
  right.backward();
}

void Car::turnLeft() {
  left.backward();
  right.forward();
}

void Car::turnRight() {
  left.forward();
  right.backward();
}

void Car::setSpeed(int speed) {
  left.setSpeed(speed);
  right.setSpeed(speed);
}

void Car::stop() {
  left.stop();
  right.stop();
}