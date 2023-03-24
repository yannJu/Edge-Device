#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

uint8_t pattern_s[8] = {
  0x02,
  0x0B,
  0x16,
  0x0B,
  0x02,
  0x08,
  0x08,
  0x0E
};

uint8_t pattern_m[8] = {
  0x00,
  0x1F,
  0x04,
  0x0A,
  0x15,
  0x04,
  0x1F,
  0x00
};

uint8_t pattern_e[8] = {
  0x0A,
  0x11,
  0x0E,
  0x02,
  0x1A,
  0x13,
  0x1A,
  0x02
};

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, pattern_s);
  lcd.createChar(1, pattern_m);
  lcd.createChar(2, pattern_e);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("H I , H E L L O -");

  lcd.setCursor(0, 1);
  lcd.print("I M ! ");

  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
}
