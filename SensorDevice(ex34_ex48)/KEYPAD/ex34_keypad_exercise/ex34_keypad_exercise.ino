#include <MiniCom.h>
#include <Keypad.h>

MiniCom com;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {7, 6, 5, 4}; // R1~R4 핀 번호
byte colPins[COLS] = {8, 9, 10, 11}; // C1~C4 핀 번호

Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //keypad 생성

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[KeyPad -]]");
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey(); //key를 비동기적으로 입력받음

  if (key) {
    String str = "key : " + (String)key;
    com.print(1, str);
  }
}
