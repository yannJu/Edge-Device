## OutputDevice(ex18_ex) 🎩
---
1. ### [RGB LED(ex18_ex19)](./RGB%20LED/)
   - `RGB LED` 센서를 이용하여 출력 예제 다루기 
     - *[ex18_RGB_LED_output_print](./RGB%20LED/ex18_RGB_LED_output_print/)* : `RGB LED` 센서 다루기
     - *[ex19_RGB_LED_withColorRed_Class](./RGB%20LED/ex19_RGB_LED_withColorRed_Class/)* : `ColorLed` 클래스화 및 라이브러리화 후 **ex18** 다루기
       - → 라이브러리화 된 파일은 [libraries](../libraries/) 에 위치
2.  ### [LCD(ex20_ex)](./LCD/)
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
        - <p style = "color: navy">항상 4자리로 포맷팅 하자 . . </p>
3.  