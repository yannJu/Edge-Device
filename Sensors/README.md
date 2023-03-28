## Sensor(ex49_) 🦾
---
1. ### [적외선 PIR 센서(ex49_ex50)](./PIR/)
   - `적외선 PIR` 센서는 **수동 적외선** 센서
   - **움직임** 을 감지하며 변화가 있을시 `HIGH` 없을시 `LOW`
   - 육각형 하나당 **적외선** 신호  
   - `센서 감도/ Delay 시간` 조절 이 가능한 **가변저항** 이 포함 되어있다.
     - 센서의 육각형 부분이 **위**로 올라올 때, 가변저항이 *오른쪽 대각선*을 바라보면 **최소**
   - `PIR센서` 관련 예제 실습
     - *[ex49_PIR_exercise](./PIR/ex49_PIR_exercise/)* :  **움직임**의 변화가 발생하면 `LED`를 점등하는 예제
     - *[ex50_PIR_withClass](./PIR/ex50_PIR_withClass/)* : [PIR.h](../libraries/PIR/PIR.h) 와  [PIR.cpp](../libraries/PIR/PIR.cpp)를 만들어서 **라이브러리화** 하기 > 위치는 [libraries](../libraries/) 로 이동
       - `Servo` 모터를 추가하여 **자동문** 기능 구현
       - **자동문** 이 닫히기 전 감지된 경우 `시간연장`
2. ### [Ultrasonic(ex51_)](./Ultrasonic/)
   - `초음파 센서` 는 벽이나 사물의 거리를 측정하는 센서
     - **초음파** 를 송출하고 _**돌아오는 거리**_ 를 이용하여 측정 
   - `VCC`, `Trigger`, `ECHO`, `GND` 로 이루어짐
   - `초음파 센서` 관련 예제 실습
     - *[ex51_Ultrasonic_exercise](./Ultrasonic/ex51_Ultrasonic_exercise/)* : `초음파센서` 를 이용하여 **거리** 측정
3. 