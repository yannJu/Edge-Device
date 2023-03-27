# Arduino _ Study Edge Device💻

1. ### [ex01_hello](./ex01_hello/)
   - `Arduino UNO` 를 이용하여 실행해보기
2. ### [LED(ex02_ex05)](./LED(ex02_ex05)/)
   - `LED` 발광 다이오드를 이용한 실습
   - `Serial` 포트 사용해보기
   - **Blink** 해보기
   - 클래스화(`객체지향적`) 으로 구현해보기
   - `라이브러리화` 구현하기
3. ### [SWITCH(ex06_ex09)](./SWITCH(ex06_ex09)/)
   - `SWITCH` 센서를 이용한 실습
   - `저항` 을 이용하여 조금이라도 무리를 줄이기 위해 **하드웨어** 는 `풀업 방식` 사용
   - 단, 헷갈릴 수 있기 때문에 일관성 유지를 위해 **논리회로** 구조는 `풀다운 방식` 처럼 구현
     - `!digitalRead()` 를 이용
4. ### [TIMER(ex10_ex13)](./TIMER(ex10_ex13))
   - `Timer` 라이브러리를 사용한 실습
     - `Timer1` & `Timer2` 다운 : 하드웨어적 타이머
       - **Interrupt** 방식
     - `SimpleTimer` 다운 : 소프트웨어적 타이머
       - **Polling** 방식
5. ### [AnalogIO(ex14_ex17)](./AnalogIO(ex14_ex17)/)
    - **아날로그**값을 입력으로 받아서 실습
    - `가변저항기` 를 이용한 아날로그 값 **입력**
    - `PWMLed` 를 이용하여 아날로그 값 **출력**
    - **PWMLed**, **Analog** 클래스 생성
6. ### [OutputDevice(ex18_ex33)](./OutputDevice(ex18_ex33)/)
    - 각종 **출력 장치** 를 이용한 다양한 예제 실행
    - `RGB_LED` 사용 : *[RGB LED](./OutputDevice/RGB%20LED/)*  
7. 