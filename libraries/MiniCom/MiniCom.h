#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SimpleTimer.h>

class MiniCom {
protected:
  long serial_bps;
  LiquidCrystal_I2C lcd;
  SimpleTimer timer;
  bool no_lcd; // lcd 사용 여부  
public:
  MiniCom(long serial_bps = 115200, int lcd_addr = 0x27);
  void setNoLcd() {no_lcd = true;};
  void init();
  void run();

  // Timer 와 관련된 Func
  int setInterval(unsigned long interval, timer_callback f);
  SimpleTimer& getTimer() {return timer;};

  // LCD light 관련
  void backlightOn();
  void backlightOff();

  // LCD 출력 관련 Func
  // 오버로딩을 통한 print 구현
  void print(int row, String msg);
  void print(int row, String title, int value);
  void print(int row, String title1, int value1, String title2, int value2);
  void print(int row, String title, double value);
  void print(int row, String title1, double value1, String title2, double value2);
};