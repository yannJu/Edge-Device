#include <SPI.h>
#include <MFRC522.h>
#include <LED.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN); // mfrc 객체 생성

LED buzzer(5); // buzzer
LED ledG(6); //green light
LED ledR(7); //red light

byte myID[4] = {161, 226, 126, 29};

boolean checkID(byte uid[]);
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
  
  // 카드가 읽힌경우 beep()
  beep();

  // ID가 등록된 것인지 확인
  bool isID = checkID(mfrc.uid.uidByte);

  if (isID) {
    ledG.on();
    delay(1000);
    ledG.off();
  }
  else {
    ledR.on();
    delay(1000);
    ledR.off();
  }
  Serial.println();
}

void beep() {
  buzzer.on();
  delay(100);
  buzzer.off();
}

boolean checkID(byte uid[]) {
  for (int i = 0; i < 4; i++) {
    if (uid[i] != myID[i]) {
      return false;
    }
  }

  return true;
}