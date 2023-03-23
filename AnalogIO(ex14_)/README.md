## AnalogIO(ex14_ex) 🎩
---
1. ### [ex14_variable_register](./ex14_variable_register)
   -  **아날로그** 입력 실습해보기
      -  `ADC`는 구현 가능
      -  `DAC`는 없다.!
         -  따라서 아날로그 **출력** 은 없음
         -  아날로그 출력처럼 보이게는 할수 있다.
   -  현재 `가변저항기` 는 오른쪽으로 갈수록 값이 커지는 경향성을 가짐
       -  `map`을 사용하여 반대로 바꾸어 주기
       -  하드웨어적인 측면에서 `+`, `-`  를 바꾸어줌
2. ### [ex15_LED_PWM_exercise](./ex15_LED_PWM_exercise)
   - `PWM` 을 이용하여 **아날로그 출력** 구현
   - `Perse` : 전류가 흐르는 폭 ?
   - `Duty` : 전류 비율을 나타냄
   - 서서히 밝아지다가 다 밝아지면 2초간 꺼짐
   - 너무 빠르게 **Perse** 가 동작하기 때문에 눈으로 보기에는 서서히 *밝아지는 것 처럼* 보임
3. 