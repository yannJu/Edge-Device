#include <PWMLed.h>

PWMLed red(9);
PWMLed green(10);
PWMLed blue(11);

void led_off(int d_time = 2000);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  one_color();
  two_color();
  three_color();
  
}

void one_color() {
  //R on
  Serial.println("[Red] color /ON/");
  red.on();
  led_off();

  //G on
  Serial.println("[Green] color /ON/");
  green.on();
  led_off();
  
  //B on
  Serial.println("[Blue] color /ON/");
  blue.on();
  led_off();
}

void two_color() {
  //두개씩 ON
  //RG, GB, BR ON
  //RG ON
  Serial.println("[Red + Green] color /ON/");
  red.on();
  green.on();
  led_off();
  
  //GB on
  Serial.println("[Green + Blue] color /ON/");
  green.on();
  blue.on();
  led_off();
  
  //BR on
  Serial.println("[Blue + Red] color /ON/");
  blue.on();
  red.on();
  led_off();
}

void three_color() {
  //전체 ON
  Serial.println("[Red + Green + Blue] color /ON/");
  red.on();
  green.on();
  blue.on();
  led_off();
}

void led_off(int d_time = 2000) {
  delay(d_time);
  //전체 OFF
  red.off();
  green.off();
  blue.off();

  Serial.println("=================");
}