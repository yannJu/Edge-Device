#include <MiniCom.h>
#include <Keypad.h>
#include <LED.h>
#include <Servo.h>
#include <EEPROM.h> // 비밀번호 값을 저장

// ========= regist val
int romIdx = 10; //EEPROM 에 저장할 번지수
int registState = 0; // 1: #이 눌린 상태 
String registStr = "";
// =======================

// ========= servo motor
Servo servo;
int servo_pin = 3;
int state = 0; // 0 : Close, 1 : Open
// ======================

// ========== Buzzer(LED)
LED buzzer(A0);
// ======================

// ========== MiniCom
MiniCom com;
int door_time_id = -1;
int btn_time_id = -1;
// ==================

// =========== Keypad
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
// ====================

// =========== pwd
String resultStr = "";
String protectStr = ""; // *표 표시 str
char *pwd = "00000000";

int failCnt = 0;
// =================

void beep(int delayTime = 100);
void setup() {
  // put your setup code here, to run once:
  com.init();
  com.backlightOff(); //평상시 백라이트 off
  com.print(0, "[[KeyPad -]]");
  
  servo.attach(servo_pin);
  servo.write(0);

  // ============ pwd 불러오기 (10 번에 저장)
  for (int i = 0; i < 8; i++) {
    pwd[i] = EEPROM.read(romIdx + i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  bool isGet = getLine();

  com.run();
  if (isGet) check();      
}

void check() {
  if (resultStr == pwd) {
    // 문 개방(서보모터)
    open();
    SimpleTimer &timer = com.getTimer();

  //===== 3초간 입력 안된경우를 체크하던 btnTimer delete
    timer.deleteTimer(btn_time_id);
    btn_time_id = -1;

    door_time_id = timer.setTimeout(3000, close);
  }
  else {
    beep(500);
    failCnt += 1;
    close();
  }
  
  resultStr = "";
  protectStr = "";
}

// '*' 을 입력받았을 때 true return -> '*' 은 제외하고 !
// 나머지 경우 false 리턴
bool getLine() {
  char key = keypad.getKey();

  if (key) { 
    // key 가 들어오면 timer -> 3초간 다음 key가 입력되는지 확인
    SimpleTimer &timer = com.getTimer();
    if (btn_time_id == -1) {
      btn_time_id = timer.setTimeout(3000, noKey);
    }
    else {
      timer.restartTimer(btn_time_id);
    }

    if (key == '*') {
      if (registState == 1) {
        regist();
        registState = 0;
      }
      else if (resultStr == "") return false;
      return true;
    }
    else { 
      // 키 입력이 들어오면 백라이트 on
      com.backlightOn();
      if (key == '#' && resultStr == "") {  // #이 들어오면 비밀번호 재설정
        registState = 1;
      }
      else { 
        beep();
        if (registState == 0) { // 비밀번호 재설정이 아닌경우
          com.print(0, "[[KeyPad -]]");
          resultStr += key;
        }
        else { // 비밀번호 재설정인 경우
          registStr += key;

          if (registStr.length() > 8) {
            // 8자리 이상인경우 경고 및 초기화
            registStr = "";
            protectStr = "";
            registState == 0;
            com.print(1, "Regist /FAIL/!");
            beep(500);

            close();
          }
          com.print(0, "[[PWD REGIST]]");
        }
        protectStr += "*";
        com.print(1, protectStr); // 키 입력한 수 만큼 * 출력          
      }
    }
  }
  return false;
}

void beep(int delayTime = 100) {
  buzzer.on();
  delay(delayTime);
  buzzer.off();
}

void open() {
  com.print(1, "[Door] is /Open/");
  servo.write(90);
  state = 1;

  failCnt = 0;
}

void close() {
  // 문 닫을 때 백라이트 off (실패했을 경우도 close())
  com.backlightOff();

  if (failCnt == 3) {
    delay(60000); // 1분간 입력 불가
    failCnt = 0;
  }
  else com.print(1, "[Door] is /Cls/");

  servo.write(0);
  state = 0;
}

void noKey() {
  // 모든 변수 초기화
  state = 0;
  door_time_id = -1;
  btn_time_id = -1;

  failCnt = 0;
  resultStr = "";
  protectStr = "";
  registStr = "";

  registState = 0;
  
  setup();
}

void regist() {
  com.print(1, "[[Regist SUCCESS]]");

  for (int i = 0 ; i < 8; i++) {
    pwd[i] = registStr[i];
    EEPROM.write(romIdx + i, pwd[i]);
  }

  registStr = "";
}