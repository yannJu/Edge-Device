#include <SPI.h>
#include <MFRC522.h>
#include <LED.h>
#include <Servo.h>
#include <MiniCom.h>
#include <BUTTON.h> // ID를 고정해두면 좋지 않기 때문에 버튼을 클릭하면 카드 등록할 수 있도록 함
#include <EEPROM.h> // myID 를 영구 저장하기 위해 EEPROM 사용

#define RST_PIN 9
#define SS_PIN 10

//mfrc ======================
MFRC522 mfrc(SS_PIN, RST_PIN); // mfrc 객체 생성
byte myID[4] = {-1, -1, -1, -1};

//Buzzer & LED ==============
LED buzzer(5); // buzzer
LED ledG(6); //green light
LED ledR(7); //red light

//Servo moter ===============
Servo servo;
const int servo_pin = 3;

//MiniCom ===================
MiniCom com;
int time_id = -1;

//Button ====================
BUTTON btn(2);

boolean checkID(byte uid[]);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
  
  servo.attach(servo_pin);
  servo.write(0);

  com.init();
  com.print(0, "[[RFID]]");

  // get EEPROM
  for (int i = 0; i < 4; i++) {
    myID[i] = EEPROM.read(i);
  }
}

void loop() {
  com.run();
  // put your main code here, to run repeatedly:
  if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
    // 태그 접촉이 되지 않거나 ID 가 읽혀지지 않는 경우
    delay(500);
    return;
  }
  
  // 카드가 읽힌경우 beep()
  beep();
  
  if (btn.read()) {
    registerID(mfrc.uid.uidByte);
  }
  else {
    // ID가 등록된 것인지 확인
    bool isID = checkID(mfrc.uid.uidByte);

    // 등록된 아이디인 경우 → 문을 열어줌
    if (isID) {
      SimpleTimer &timer = com.getTimer();

      open();
      time_id = timer.setTimeout(3000, close);
    }
    else {
      ledR.on();
      delay(1000);
      ledR.off();
    }
  }
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

void open() {
  servo.write(90);
  com.print(1, "[Door]is/OPEN/");

  ledG.on();
  delay(1000);
  ledG.off();
}

void close() {
  com.print(1, "[Door]is/CLOSE/");
  servo.write(0);
}

void registerID(byte uid[]) {
  com.print(1, "Regist Success-");
  for (int i = 0; i < 4; i++) {
    myID[i] = uid[i];
    EEPROM.write(i, uid[i]); //i번지에 uid[i] 저장
  }
}