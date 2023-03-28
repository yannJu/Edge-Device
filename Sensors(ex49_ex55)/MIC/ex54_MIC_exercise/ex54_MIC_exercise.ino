#include <PWMLed.h>
#include <MiniCom.h>

MiniCom com;

PWMLed led(9);

int mSensor = A0;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[Mic]]");  
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();

  int readVal = analogRead(mSensor);
  int lightVal = readVal / 4;

  com.print(1, "RV:", readVal, "LV:", lightVal);
  led.setValue(lightVal);
  
  delay(200);
}
