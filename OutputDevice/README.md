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
4.  ### [BUZZER(ex26_ex)](./BUZZER/) 
    - **능동** 부저, **수동** 부저
    -   `능동부저` : ON/OFF 로 구성되어 **한 음** 만 출력
    -   `수동부저` : **진동** 에 의해 출력
    -  `Buzzer` 를 이용하여 예제 실습
       -  *[ex26_Buzzer_exercise](./BUZZER/ex26_Buzzer_exercise/)* : 능동`Buzzer` 를 사용하여 `버튼`이 **클릭**되면 2초간 소리내고 끄기
          -  `Buzzer`와 `Led`가 연결되어있음 → `LED` 객체로 `Buzzer`를 불러와도 됨
5.  