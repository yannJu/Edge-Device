#include <SoftwareSerial.h>

SoftwareSerial BTSerial(13, 12); // BT TX RX 순으로 작성

void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available()) Serial.write(BTSerial.read()); //PC에서 BT값을 읽어옴
  if (Serial.available()) BTSerial.write(Serial.read()); //BT에서 PC 값을 읽어옴
}
