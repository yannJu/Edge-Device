#include <MiniCom.h>
#include <Keypad.h>
#include <LED.h>
#include <Servo.h>

Servo servo;
int servo_pin = 3;
int state = 0; // 0 : Close, 1 : Open

LED led(12);

MiniCom com;
int time_id = -1;

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
String resultStr = "";
String pwd = "100115";

void beep(int delayTime = 100);
void setup() {
  // put your setup code here, to run once:
  com.init();
  com.backlightOff();
  com.print(0, "[[KeyPad -]]");
  
  servo.attach(servo_pin);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool isGet = getLine();

  com.run();
  if (isGet) {
    if (resultStr == pwd) {
      // 문 개방(서보모터)
      open();
      SimpleTimer &timer = com.getTimer();

      time_id = timer.setTimeout(3000, close);
    }
    else beep(500);
    
    resultStr = "";
  }      
}

// '*' 을 입력받았을 때 true return -> '*' 은 제외하고 !
// 나머지 경우 false 리턴
bool getLine() {
  char key = keypad.getKey();

  if (key) {
    beep();
    if (key == '*') {
      return true;
    }
    else {
      resultStr += key;
    }
  }
  return false;
}

void beep(int delayTime = 100) {
  led.on();
  delay(delayTime);
  led.off();
}

void open() {
  com.print(1, "[Door] is /Open/");
  servo.write(90);
  state = 1;
}

void close() {
  com.print(1, "[Door] is /Cls/");
  servo.write(0);
  state = 0;
}