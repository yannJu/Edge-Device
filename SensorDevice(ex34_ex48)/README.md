## SensorDevice(ex34_ex48) 🎩
---
1. ### [KEYPAD(ex34_ex36)](./KEYPAD/)
   -  `Keypad` 를 이용하여 값을 입력받을 수 있다.
   -  `Col` 에 해당하는 핀인 **C1, C2, C3, C4** 가 있다.
   -  `Row` 에 해당하는 핀인 **R1, R2, R3, R4** 가 있다.
   -  `Keypad`와 관련된 예제 실습
      -  *[ex34_keypad_exercise](./KEYPAD/ex34_keypad_exercise/)* : `Keypad`를 정의하고 입력받기
      -  *[ex35_keypad_exercise2](./KEYPAD/ex35_keypad_exercise2/)* : 지정한 **pwd** 값과 _**같은**_ 값이 들어온 경우 `Servo` 모터를 이용(문개방), **_다른_** 값이 들어온 경우 `BUZZER` 를 이용하여 경고음
      -  *[ex36_keypad_door_lock](./KEYPAD/ex36_keypad_door_lock/)* : 기능 추가
         -  default : backlight `off`
         -  **3초** 동안 버튼 안누르면 꺼짐
         -  일정 횟수 만큼 틀리면 **1분** 동안 입력 금지
         -  . . 등등
2. ### [JOY STICK(ex37_ex38)](./JOY%20STICK/)
   -  `X`, `Y` 의 **아날로그** 입력값을 받음
   -  조이스틱을 누름으로써 `Z` 값을 입력받음
   -  자동차 속도조절, 회전, 카메라 회전등에 사용
   -  `Joy Stick` 관련 예제 실습
      -  *[ex37_joystick_exercise](./JOY%20STICK/ex37_joystick_exercise/)* : `JoyStick` 센서를 이용하여 **아날로그** 값 입력받기
      -  *[ex38_joystick_with_lcd](./JOY%20STICK/ex38_joystick_with_lcd/)* : `JoyStick` 의 값을 입력받아 `LCD`에 출력하고 `Servo` 모터의 **회전각**으로 출력하기
3. ### [RFID(ex39_ex41)](./RFID/)
   - `RFID` : 태그 안에 **코일** 이 감겨져있어서 특정 **주파수** 를 발생시키는 회로가 들어있음
   - `RFID 리더기` 가 전파를 약하게 생성 → `태그` 가 전자기 유도 발생 → 자기장이 흐름으로써 **전원**으로 사용 
   - `SPI통신` : `I2C`는 **address** 통해 통신하는데, `SPI`는 **Master-Slave** 방식으로 통신
     - `MOSI(아두이노▷디바이스)`, `MISO(아두이노◁디바이스)`, `SCK`, `SS` 를 포함해야하므로 최소 **4개** 의 선 필요
   - `MFRC522` 라이브러리 설치 *(gitIgnore)*
   - `RFID` 관련 예제 실습
     - *[ex39_RFID_exercise](./RFID/ex39_RFID_exercise/)* : `RFID` 를 통해 **카드** 및 **동글** 이 잘 인식되는지 확인
     - *[ex40_RFID_exercise2](./RFID/ex40_RFID_exercise2/)* : `RFID` 의 **ID** 확인 여부를 통해 `Buzzer` 및 `LED` 동작
     - *[ex41_door_lock_with_RFID](./RFID/ex41_door_lock_with_RFID/)* :  `ex40`에 `Button` 을 누른상태로 **카드** 접촉시 **ID**가 등록되게 하는 기능 추가
4. ### [CdS(ex43_ex44)](./CdS/)
   - `조도센서`는 밝기를 **입력** 으로 받음
   - **절대값**을 측정하는 것이 아닌 `밝은가  어두운가` 를 측정
   - **밝을수록** 저항이 `↑` : 전압 `↑`
   - **어두울수록** 저항이 `↓` : 전압 `↓`
   - `조도센서` 관련 예제 실습
     - *[ex43_CdS_exercise](./CdS/ex43_CdS_exercise/)* : `CdS` 센서를 이용하여 **LED** 점등 + 값이 **bouncing** 하는 것을 해결 *(평균점 || 기준점을 2개)*
     - *[ex44_CdS_withPWMLED](./CdS/ex44_CdS_withPWMLED/)* : **밝기** 에 따라 **LED** 값을 조정 (아날로그 출력)
5. ### [온습도 센서(ex45_ex46)](./%EC%98%A8%EC%8A%B5%EB%8F%84%EC%84%BC%EC%84%9C/)
   - `DHT11` 센서 
     - `Digital Pin` 에 연결하여 **0.1통신** 을 함 (_One-Wire 통신_ 이라고도 함)
     - **2초 이상**의 샘플간격이 있으므로 그 *이상의 텀*을 두고 측정 해야함
     - *[ex45_temperate_exercise](./%EC%98%A8%EC%8A%B5%EB%8F%84%EC%84%BC%EC%84%9C/ex45_temperate_exercise/)* : `DHT11` 센서를 이용하여 **섭씨, 화씨, 습도** 측정
   - ` LM35` 센서
     - **트랜지스터** 와 유사하게 생김
     -  `1℃`가 변함에 따라 출력전압을 **10mV**씩 올린다.
     -  *[ex46_LM35](./%EC%98%A8%EC%8A%B5%EB%8F%84%EC%84%BC%EC%84%9C/ex46_LM35/)* : `LM35` 센서를 이용하여 **온도** 측정
6.  ### [기울기 센서(ex47_ex48)](./%EA%B8%B0%EC%9A%B8%EA%B8%B0%20%EC%84%BC%EC%84%9C/)
    -  `기울기 센서` 내에 **볼** 이 들어있어 전류가 흐름
    -  *[ex47_KIT_07](./%EA%B8%B0%EC%9A%B8%EA%B8%B0%20%EC%84%BC%EC%84%9C/ex47_KIT_07/)* : **기울기** 를 감지하여 `LED` 점등 →  **_레벨트리거_**
    -  *[ex48_KIT_07_edgeTrigger](./%EA%B8%B0%EC%9A%B8%EA%B8%B0%20%EC%84%BC%EC%84%9C/ex48_KIT_07_edgeTrigger/)* : **만보기** 를 구현 → **_엣지트리거_** 여야 한다.