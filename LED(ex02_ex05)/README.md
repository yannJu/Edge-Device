## LED관련 Exercise (ex02~ex05) 🖼
---
1. ### [ex02_pin_practice](./ex02_pin_practice/)
   - `Pull Up` 과 `Pull Down` 방식을 이용해보기
   - **발광다이오드** 를 이용해 `Blink` 기능 구현
2. ### [ex03_pin_state](./ex03_pin_state/)
   - `Pull Up` 과 `Pull Down` 을 통해 **state** 확인
   - `delay` 조절
3. ### [ex04_4led_control](./ex04_4led_control)
   - *[ex04_4led_control.ino](./ex04_4led_control/ex04_4led_control.ino)*
     - 4개의 `led` 다이오드를 *차례대로* 불이 켜지도록 구현
   - *[ex04_4led_forloop_control.ino](./ex04_4led_control/ex04_4led_forloop_control.ino)* 
     - `for문`과 `array`를 이용하여 이전의 코드를 구현
     - 동일한 **sketch** 에서 작업하여 `ex04_4led_control` 를 주석처리
4.  ### [ex05_led_with_object](./ex05_led_with_object)
    - `객체지향` 적으로 구현
    -  이전에 `array`를 이용하여 순차적으로 점열했던 부분을 **LED** 라는 `객체` 배열로 구현
    -  `LED` 객체는 앞으로 계속 사용하기 때문에 *[libraries](../libraries)* 폴더에 넣어 **라이브러리화** 해야함
    -  *[LED.h](../libraries/LED/LED.h)* 
       -  객체 `Header` 파일
    -  *[LED.cpp](../libraries/LED/LED.cpp)* 
       -  클래스 `정의` 파일 
    -  *[ex05_led_with_object.ino](./ex05_led_with_object/ex05_led_with_object.ino)* 
       -  아두이노 동작 소스 코드
       -  `LED` 객체를 이용하여 **ex04** 를 구현
       -  3가지 방안으로 **blink**
       -   한번 순차적으로 돌면 `3번` 깜빡이기 기능 추가 