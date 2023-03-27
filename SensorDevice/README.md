## SensorDevice(ex34_ex) 🎩
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
2. ### [JOY STICK(ex37_ex)](./JOY%20STICK/)
   -  `X`, `Y` 의 **아날로그** 입력값을 받음
   -  조이스틱을 누름으로써 `Z` 값을 입력받음
   -  자동차 속도조절, 회전, 카메라 회전등에 사용
   -  `Joy Stick` 관련 예제 실습
      -  *[ex37_joystick_exercise](./JOY%20STICK/ex37_joystick_exercise/)* : `JoyStick` 센서를 이용하여 **아날로그** 값 입력받기
      -  *[ex38_joystick_with_lcd](./JOY%20STICK/ex38_joystick_with_lcd/)* : `JoyStick` 의 값을 입력받아 `LCD`에 출력하고 `Servo` 모터의 **회전각**으로 출력하기
3. 