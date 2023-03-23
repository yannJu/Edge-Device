## SWITCH관련 Exercise (ex06~ex09) 🎍
---
1. ### [ex06_switch.ino](./ex06_switch)
   - `SWITCH` 의 상태를 이용하여 **INPUT** 으로 받기
   - **INPUT** 으로 받은 값을 `발광 다이오드` 센서 값으로 `setValue()` 
2.  ### [ex07_inner_pullup.ino](./ex07_inner_pullup)
    - `SWITCH` 상태를 입력받기
    - **Falling Edge** 와 **Rising Edge** 에 따라 `Switch` 클릭 횟수 세기
    - 그에 따라 `발광 다이오드` 점멸 제어
       - `SWITCH` 눌려질 때 마다 4개의 LED 가 순차로 **점멸** 되도록 !
3.  ### [ex08_button_class_exercise](./ex08_button_class_exercise)
    - `Button`  클래스([BUTTON.h](../libraries/BUTTON/BUTTON.h), [BUTTON.cpp](../libraries/BUTTON/BUTTON.cpp)) 만들기
      - **라이브러리화** 하여 [libraries](../libraries)에  폴더를 생성
    - **typedef** 를 이용하여 함수에 대한 `포인터` 를 사용하여 함수를 *인자* 로 넘겨준다. 
      - `BUTTON` 클래스에서는 **Button** 과 관련된 동작만 할 수 있도록!
4.  ### [ex09_Switch_Button_practice](./ex09_Switch_Button_practice)
    -  **1초** 마다 4개의 **led** 가 순차적 점등
    -  `Button` 이 클릭되었을 때 **7** 번 **led** 점등
    -  `delay()` 사용시 **비동기**적 기능이 실행되지 않음
       -  `time()` 을 이용하여 `1초` 마다 점등되도록 함