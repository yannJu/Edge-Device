## OutputDevice(ex18_ex) 🎩
---
1. ### [RGB LED(ex18_ex19)](./RGB%20LED/)
   - `RGB LED` 센서를 이용하여 출력 예제 다루기 
     - *[ex18_RGB_LED_output_print](./RGB%20LED/ex18_RGB_LED_output_print/)* : `RGB LED` 센서 다루기
     - *[ex19_RGB_LED_withColorRed_Class](./RGB%20LED/ex19_RGB_LED_withColorRed_Class/)* : `ColorLed` 클래스화 및 라이브러리화 후 **ex18** 다루기
       - → 라이브러리화 된 파일은 [libraries](../libraries/) 에 위치
2.  ### [LCD(ex20_ex23)](./LCD/)
    - **I2C 통신 모듈**이 부착되어 있음
    - `GND`, `VCC`, `SDA(A4)`, `SCL(A5)` 4개의 디지털 선  
    - 버스 *(BUS)* 사용
    - **Arduino IDE** 에서 file > Examples > Wire > i2c_scanner > Upload
      - I2C Device **주소** 스캔
      - 주로 `0x27` 이 나옴 `:3`
    - `LiquidCrystal_I2C` 라이브러리 설치 (**git Ignore**)
    - `LCD ` 를 이용한 여러 예제 실습
      - *[ex20_printString](./LCD/ex20_printString/)* : `LCD`  장치에 문자열 띄우기
      - *[ex21_StringScroll](./LCD/ex21_StringScroll/)* : `LCD`  장치에 문자열 띄워서 **스크롤** 시키기
      - *[ex22_print_user_define_pattern](./LCD/ex22_print_user_define_pattern/)* : 직접 **pattern** 만들어 띄우기
      - *[ex23_LCD_with_varResister](./LCD/ex23_LCD_with_varResister/)* : `가변저항기` 값을 **입력** 받아 `LCD`에 **출력**
        - "1023" 이후 값을 *줄일 때* (4자리 → 3자리)  예전에 있던 값이 덮어씌워지지 않아서 **남아있음**
        - "1023" 에서 "910" 이 되고 싶어도 "9103" 과 같이 남음
        - `clear` 후에 다시 `print` 하도록 하자 `'.'` ? ▷ 너무 심하기 **깜빡거림**
        - <p style = "color: navy">항상 4자리로 포맷팅 하자 . .   → sprintf</p>
3.  ### [MINICOM(ex24_ex25)](./MINICOM)
    -  `Timer`, `LiquidCrystal_I2C`, `Serial` 과 같은 경우 자주 쓰임
    -  따라서 `MiniCom` 이라는 클래스를 만들어 호출시 사용
    -  `MiniCom` 은 [libraries](../libraries/) 에 위치
    -  `LCD` 초기화, `Timer` 정의, 출력함수 구현 등으로 이루어짐
    -  `MiniCom` 을 이용한 예제 실습
       -  *[ex24_MiniCom_exercise](./MINICOM//ex24_MiniCom_exercise)* : *1초 간격* 으로 `LED`를 **blink** + *현재 상태* 를 `LCD` 로 **출력**해보기
          -  **ex24** 의 `check()` 함수를 수정하여 `센싱` 시 종종 골격으로 사용
       -  *[ex25_LEDcontrol_withLCD](./MINICOM/ex25_LEDcontrol_withLCD/)* : `가변저항기` 에서 **입력** 받아 `LED` 밝기 조절 및 `LCD` 에 출력
    -  `MiniCom` 을 **base** 로 사용하여 다른 기능에서 필요시 **상속** 받아 사용할 예정
4.  ### [BUZZER(ex26_ex29)](./BUZZER/) 
    - **능동** 부저, **수동** 부저
    -   `능동부저` : ON/OFF 로 구성되어 **한 음** 만 출력
    -   `수동부저` : **진동(Perse 파)** 에 의해 출력
    -  `Buzzer` 를 이용하여 예제 실습
       -  *[ex26_Buzzer_exercise](./BUZZER/ex26_Buzzer_exercise/)* : 능동`Buzzer` 를 사용하여 `버튼`이 **클릭**되면 2초간 소리내고 끄기
          -  `Buzzer`와 `Led`가 연결되어있음 → `LED` 객체로 `Buzzer`를 불러와도 됨
       -  *[ex27_playMelody_withBuzzer](./BUZZER/ex27_playMelody_withBuzzer/)* : 수동`Buzzer`를 이용하여 **곰세마리** 연주하기
          -  `버튼` 을 누르면 연주를 **중단/시작** 하기 → 어떻게 ? `ex29`  참조
       -  *[ex28_playMelody_with_pitches](./BUZZER/ex28_playMelody_with_pitches/)* : **주파수 응용파일** 을 받아 범용적으로 처리하기
          -  `File > Examples > Digital > toneKeyboard` 에 나와있음 → **Copy**  해서 쓰자 . . 
          - Melody 와 Duration 을 외부에서 검색해서 헤더파일로 추가
        - *[ex29_create_Melody_Class](./BUZZER/ex29_create_Melody_Class/)* : **Melody** 클래스화 & 라이브러리화 를 통한 *범용적* 구현
          - **Melody** 클래스는 [libraries](../libraries/) 폴더에 위치
          - 음악을 **재생** 하고 있었는지의 여부를 *체크*
          - **duration** 을 `millis()` 를 이용하여 체크
5.  ### [RELAY(ex30)](./RELAY/)
    - `NC`, `NO` `Signal` 로 이루어진 센서 
    - `Switch` 와 동일하게 직관적 연결을 위해 `NO` 부분에 전원 연결
    - `RELAY` 관련 예제 실습
      - *[ex30_RelaySensor](./RELAY/ex30_RelaySensor/)* : `MiniCom` 클래스를 함께 사용 , 버튼을 누르면 **0.5초** 마다 **Blink**
6.  ### [SERVO(ex31_ex)](./SERVO/)
    - `0-180` 도 사이의 각도를 표현할 수 있다.
    - **Servo.h** 라이브러리를 이용하여 회전 시킬 수 있다.
    - <a style = "color : orange">주황색</a> 선은 `Signal`, <a style = "color : red">빨간색</a> 선은 `VCC`, <a style = "color : brown">갈색</a> 선은 `GND`
    - `attach`, `write` 함수가 핵심
    - `Servo` 관련 예제 실습  
      - *[ex31_servo_exercise](./SERVO/ex31_servo_exercise/)* : `Servo` 센서에 값을 **입력** 하여 모터 회전시키기
      - *[ex32_servo_with_variable_register](./SERVO/ex32_servo_with_variable_register/)* : `가변 저항기` 에서 값을 **입력** 받아 아날로그 값을 모터에 출력하여 회전시키기
7.  