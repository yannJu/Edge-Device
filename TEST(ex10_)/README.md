## ?? (ex10~) ⚾
---
1. ### [ex10_usingMsTimer](./ex10_usingMsTimer)
   - `MsTimer` 라이브러리를 설치
     - **libraries** 폴더에 저장됨 → `gitignore` 해 둠
   - 주로 `Timer0` 은 잘 안씀
     - `delay()` 등에서 이미 사용하고 있기 때문에
   - `Timer2` 를 이용하여 하드웨어가 **일정한 시간** 간격으로 함수를 실행시켜줌 
     - 하드웨어가 동작하기 때문에 `loop()`는 비워둔 상황
     - [ex09_Switch_Button_practice](../SWITCH(ex06_ex09)/ex09_Switch_Button_practice) 에서 했던 것 처럼 **동시작업**  이 가능해진 환경
2. ### [ex11_usingTimerOne](./ex11_usingTimerOne)
   - `TimerOne` 라이브러리 설치
   - `MsTimer` 혹은 `TimerOne` 모두 **하드웨어** 타이머
     - 한가지의 **Interrupt** 밖에 사용할 수 없다 . . 
     - **소프트웨어** 타이머를 쓰자 . . !
3. ### [ex12_usingSimpleTimer](./ex12_usingSimpleTimer)
   - `SimpleTimer` 를 외부(**GIT**) 에서 다운 후 [libraries](../libraries) 폴더로 이동
   - **Polling** 방식을 쓰기 때문에 꼭 `loop()`에서 `run()`을 실행
     - 속도면에서는 Polling 이 좀 떨어짐 . . ㅠ . ㅠ
   - 주로 `setTimeout()` 과 `restartTimer()` 를 묶어서 쓸 때가 많음
4. ### [./ex13_simpleTimer_exercise/](./ex13_simpleTimer_exercise/)
   - **1초** 마다 특정 `led`가 점등
     - 버튼을 **1번** 클릭시 : **0.6**초 마다 점등
     - 버튼을 **2번** 클릭시 : **0.3**초 마다 점등
     - 이후 버튼 다시 클릭시 `default` 초로 변경
   - `setInterval()` 의 경우 `timer_id`를 리턴
     - 따라서 꼭 . . **time_id** 를 변수에 할당시켜야 동작 함 `- . -`
5.  