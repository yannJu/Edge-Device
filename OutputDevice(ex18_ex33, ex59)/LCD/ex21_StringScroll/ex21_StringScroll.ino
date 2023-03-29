#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  // lcd.backlight(); // no light

  lcd.setCursor(0, 0); // cursor home (0, 0)
  lcd.print("1++++++++23--------45********67########8");

  lcd.setCursor(0, 1);
  lcd.print("1++++++++23--------45********67########8");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int n = 0; n < 80; n++) {
    lcd.scrollDisplayLeft();
    delay(500);
  }
  
  for (int n = 0; n < 80; n++) {
    lcd.scrollDisplayRight();
    delay(500);
  }

  delay(4000);
}
