#include <BUTTON.h>

#define NOTE_C4   262  // 4옥타브 도
#define NOTE_D4   294  // 4옥타브 레
#define NOTE_E4   330  // 4옥타브 미
#define NOTE_G4   392  // 4옥타브 파
#define NOTE_A4   440  // 4옥타브 솔
#define NOTE_C5   523  // 5옥타브 라

#define  NUM  49

int melody[NUM] = {     // 곰 세마리      
   NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,				// 도도도도도
   NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,     		// 미솔솔미도
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4,  // 솔솔미솔솔미     
   NOTE_C4, NOTE_C4, NOTE_C4,       							// 도도도
   
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,  	// 솔솔미도
   NOTE_G4, NOTE_G4, NOTE_G4,       		// 솔솔솔
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,    // 솔솔미도
   NOTE_G4, NOTE_G4, NOTE_G4,      			// 솔솔솔
   
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,     // 솔솔미도
   NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4,  // 솔솔솔라솔
   NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4,     // 도솔도솔
   NOTE_E4, NOTE_D4, NOTE_C4};     // 미레도

// 음표 길이
int noteDuration[NUM] ={
  4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 8, 8, 4, 8, 8, 4, 4, 4, 2, 
  4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 
  4, 4, 4, 4, 8, 8, 8, 8, 2, 4, 4, 4, 4, 4, 4, 2
};

const int speaker_pin = 9;

BUTTON btn(2);
int btnClick = 0;

int time;

void setup() {
  pinMode(speaker_pin, OUTPUT);
  btn.setCallBack(btnPressed);

  Serial.begin(9600);
}

void loop() {
  btn.check();
}

void btnPressed() {
  int m, d, dd;
  int nowTime, oldTime;

  if (++btnClick % 2) {
  Serial.println(btnClick);
    for (m = 0; m < NUM; m++) {
      d = 1000 / noteDuration[m];
      dd = d * 1.3;

      tone(speaker_pin, melody[m], d);
      // delay(dd); // tone 이 비동기이기 때문에 delay 를 주지 않으면 바로 for문 다음 loop로 넘어가게 됨
      nowTime = millis();
      oldTime = millis();
      while(nowTime - oldTime > dd) {
        oldTime = nowTime;
        nowTime = millis();
      }
    }
    delay(1000);
  }
  else {
    noTone(speaker_pin);
  }  
}
