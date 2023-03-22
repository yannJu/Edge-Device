const int led_pins[4] = {3, 4, 5, 6};
// 출력할 index 번호에 맞추어 High, Low 설정
const int led_outs[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};
int out_no = 0; // 출력할 index 번호

void setup() {
  int n;

  for (n = 0; n < 4; n++) {
    pinMode(led_pins[n], OUTPUT);
    digitalWrite(led_pins[n], LOW); // default 가 LOW 이므로 굳이 할 필요 없음
  }
}

void loop() {
  int n;

  for (n = 0; n < 4; n++) {
    digitalWrite(led_pins[n], led_outs[out_no][n]);
  }    
    ++out_no %= 4;
    delay(1000);                                   
}