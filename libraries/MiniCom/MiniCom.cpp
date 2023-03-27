#include "MiniCom.h"

MiniCom::MiniCom(long serial_bps, int lcd_addr) : serial_bps(serial_bps), lcd(lcd_addr, 16, 2) {
  no_lcd = false;
}
void MiniCom::init() {
  Serial.begin(serial_bps);
  if (!no_lcd) { // lcd 를 사용한다면 init 하기
    lcd.init();
    lcd.backlight();
  }
}

// Timer 와 관련된 Func
void MiniCom::run() { // 타이머 실행
  timer.run();
}
int MiniCom::setInterval(unsigned long interval, timer_callback f) { // 타이머 Interval Set 후 반환
  return timer.setInterval(interval, f);
}

  // LCD light 관련
void MiniCom::backlightOn() {
  lcd.backlight();
}
void MiniCom::backlightOff() {
  lcd.noBacklight();
}

// LCD 출력 관련 Func
// 오버로딩을 통한 print 구현
void MiniCom::print(int row, String msg) {
  if (no_lcd) return; // 만약 lcd 를 쓰지 않는다면 그냥 return
  char buf[17];

  sprintf(buf, "%-16s", msg.c_str()); // 16자리 formatting + 들어오는 msg 를 char 로 (sprint 는 c함수이기 때문에 String 을 모르므로 char 배열로만 받을 수 있음)
  lcd.setCursor(0, row); // row번째 행에 cursor set
  lcd.print(buf);
}

void MiniCom::print(int row, String title, int value) {
  if (no_lcd) return;
  String buf = title + value;

  print(row, buf); // 매개변수가 (int, string) 인 print 재사용
}

void MiniCom::print(int row, String title1, int value1, String title2, int value2) {
  if (no_lcd) return;
  String buf = title1 + value1 + " , " + title2 + value2;

  print(row, buf);
}

void MiniCom::print(int row, String title, double value) {
  if (no_lcd) return;
  String buf = title + value;

  print(row, buf); // 매개변수가 (int, string) 인 print 재사용
}

void MiniCom::print(int row, String title1, double value1, String title2, double value2) {
  if (no_lcd) return;
  String buf = title1 + value1 + " , " + title2 + value2;

  print(row, buf);
}