char soundInputPin = A0;
int ledLevel[3] = {10, 11, 12};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(ledLevel[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int soundInput = analogRead(soundInputPin);
  int soundLevel = map(soundInput, 300, 550, 0, 2); // threshold 값을 잘 조정해야함

  Serial.print(soundInput);
  Serial.print(" ");
  Serial.println(soundLevel);
  for (int i = 0; i < 3; i++) digitalWrite(ledLevel[i], LOW);
  for (int i = 0; i < soundLevel; i++) digitalWrite(ledLevel[i], HIGH);

  delay(200);
}
