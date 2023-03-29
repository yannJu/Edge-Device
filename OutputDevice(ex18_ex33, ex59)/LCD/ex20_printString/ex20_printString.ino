#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init(); // Initialize LCD

  // print a message to the LCD;
  // using BackLight ===========================
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello, world!");

  lcd.setCursor(2, 1);
  lcd.print("Yannjo Arduino");
  
  lcd.setCursor(0, 2);
  lcd.print("LCM IIC 2004 www");
  
  lcd.setCursor(2, 3);
  lcd.print("yammy yam");
}

void loop() {
  // put your main code here, to run repeatedly:

}
        