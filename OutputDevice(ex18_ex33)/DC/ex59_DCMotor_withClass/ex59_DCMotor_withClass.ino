int in1Pin = 7; // 좌측 바퀴 in1
int in2Pin = 6; // 좌측 바퀴 in2
int ENAPin = 5; // 좌측 바퀴 GND

int in1Pin = 8; // 우측 바퀴 in1
int in2Pin = 9; // 우측 바퀴 in2
int ENAPin = 10; // 좌측 바퀴 GND

void setup() {
  // put your setup code here, to run once:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(ENAPin, OUTPUT);

  analogWrite(ENAPin, 180);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);

  delay(2000);
}
