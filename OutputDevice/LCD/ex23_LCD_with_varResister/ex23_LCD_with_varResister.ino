#include <LiquidCrystal_I2C.h>
#include <Analog.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Analog sensor(A0, 1023, 0); // 가변 저항 센서

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  char buf[17]; // 최대 16자리까지 출력해야하며 String 이므로 공백 포함 16 + 1 = 17

  int value = sensor.read();
  lcd.setCursor(0, 0);

  // lcd.clear(); 오히려 더 깜빡임이 심해짐
  sprintf(buf, "value : [%4d]", value); // formatting 하여 string 을 출력하겠다 ! : %4d , 4자리 digit 으로 포맷팅
  lcd.print(buf);
}
