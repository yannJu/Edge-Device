#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN); // mfrc 객체 생성

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
    // 태그 접촉이 되지 않거나 ID 가 읽혀지지 않는 경우
    delay(500);
    return;
  }
  Serial.print("Card UID : ");

  for (byte i = 0; i < 4; i++) {
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();
}
