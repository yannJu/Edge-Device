#include <ColorLed.h>

ColorLed leds(9, 10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // pwm_one_color();
  // pwm_two_color();
  // pwm_three_color();
  leds.random();
  delay(2000); // delay 에 따라 무드등 조절 가농 ㅎ 
}

void pwm_one_color() {
  Serial.println("[Red] is /on/ ====== ");
  for (int i = 0; i < 256; i += 50) {
    leds.rgb(i, 0, 0);
    delay(500);
  }
  leds.off(1000);
  Serial.println("=====================");

  Serial.println("[Green] is /on/ ====== ");
  for (int i = 0; i < 256; i += 50) {
    leds.rgb(0, i, 0);
    delay(500);
  }
  leds.off(1000);
  Serial.println("=====================");

  Serial.println("[Blue] is /on/ ====== ");
  for (int i = 0; i < 256; i += 50) {
    leds.rgb(0, 0, i);
    delay(500);
  }
  leds.off(1000);
  Serial.println("=====================");
}

void pwm_two_color() {
  Serial.println("[Red + Green] is /on/ ====== ");
  for (int i = 0; i < 256; i += 50) {
    for (int j = 0; j < 256; j += 50) {
      leds.rgb(i, j, 0);
      delay(500);
    }
  }
  leds.off(1000);
  Serial.println("=====================");

  Serial.println("[Green + Blue] is /on/ ====== ");
  for (int i = 0; i < 256; i += 50) {
    for (int j = 0; j < 256; j += 50) {
      leds.rgb(0, i, j);
      delay(500);
    }
  }
  leds.off(1000);
  Serial.println("=====================");

  Serial.println("[Blue + Red] is /on/ ====== ");
  for (int i = 0; i < 256; i += 50) {
    for (int j = 0; j < 256; j += 50) {
      leds.rgb(j, 0, i);
      delay(500);
    }
  }
  leds.off(1000);
  Serial.println("=====================");
}

void pwm_three_color() {
  Serial.println("[All Color] is /on/ ====== ");
  for (int i = 0; i < 256; i += 50) {
    for (int j = 0; j < 256; j += 50) {
      for (int k = 0; k < 256; k += 50) {
        leds.rgb(i, j, k);
        delay(300);
      }
    }
  }
  leds.off(1000);
  Serial.println("=====================");
}