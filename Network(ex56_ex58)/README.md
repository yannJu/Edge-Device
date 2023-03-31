## Network 관련 Exercise (ex56_ex58, ex60) 📿
---
1. ### [Bluetooth(ex56_ex58)](./Bluetooth/)
   - `Bluetooth` 를 이용한 통신
   - 센서의 **RXD** 는 센서 입장에서 **RXD** 즉 아두이노에서는 **TXD** ▷ **TXD** 는 반대
   - 유선 `Serial` 통신
   -  `Bluetooth` 는 `아두이노` 로 **3.3V** 를 보냄
      -  `아두이노`는 **1.5V** 이상이면 **HIGH** 로 인식
      -  하지만 반대의 경우(`아두이노` 에서 `Bluetooth`) **5V** 로 보내게 됨
      -  더 많은 전압이 들어오므로 문제가 될 수 있다.
      -  `아두이노` 디지털 핀 에서 보통 **저항** 을 연결한다.
   -  `SoftwareSerial` 을 이용하여 **소프트웨어** 적으로 통신  
      -  소프트웨어적 통신으로 **느리다** (9600 이후로는 깨짐)
   -  [Bluetooth Paring](./Bluetooth/ex56_Bluetooth_paring/) : `블루투스` 페어링 준비 코드
      -  `Serial 모니터` 에 `AT+NAME` 을 통해 블루트스 명을 출력
      -  `AT+NAME[변경이름]` 을 통해 블루투스 명을 변경할 수 있다.
      -  `AT+PIN[변경 pin]` 을 통해 PIN을 변경할 수 있다.
   -  `Bluetooth` 관련 예제 실습
      -  *[ex57_Bluetooth_communicate](./Bluetooth/ex57_Bluetooth_communicate/)* : **아두이노** 프로그래밍으로 블루투스 모듈 통신
         -  **아두이노**의 `loop` 도는 속도가 `Serial` 의 9600 보다 빠르기 때문에 `delay`를 줌으로써 수신 문자열이 **끊김**을 방지
      -  *[ex58_Bluetooth_BtMiniCom](./Bluetooth/ex58_Bluetooth_BtMiniCom/)* : `Bluetooth` 기능을 **라이브러리화** > [libraries](../libraries/) 폴더에 이동
         -  `MiniCom`을 상속하여 구성
         -  `LED`와 `SERVO` 센서를 통해 실습 진행
      -  *[ex34 수정](../SensorDevice(ex34_ex48)/KEYPAD/ex35_keypad_exercise2)* : `KEYPAD` 대신 `Bluetooth` 통신으로 문열기
2. ### [NodeMCU(ex60_ex)](./NodeMCU/)
   - `WiFi` 를 통한 통신이 가능하게 함
   - **esp8266** 보드 매니저 설치
   - `NodeMCU` 관련 예제 실습
     - *[ex60_getIp_usingMCU](./NodeMCU/ex60_getIp_usingMCU/)* : **IP주소** 를 읽어와 동작시키기 
       - **esp8266** 의 `board`를 설치하여 `NodeMCU` 의 **port** 번호로 업로드
       - _**2.4Ghz**_ 로만 연결 가능
     - *[ex61_nodeMCU_withClass](./NodeMCU/ex61_nodeMCU_withClass/)* : `WifiMiniCom` 라는 라이브러리를 만들어서 구현
       - `MiniCom` 을 상속받아 구현
       - 헤더파일등은 [libraries](../libraries/) 에 이동
     - *[ex62_nodeMCU_webserver](./NodeMCU/ex62_nodeMCU_webserver/)* : `NodeMCU` 를 이용하여 **웹서버** 만들기
       - `NodeMCU` 가 **웹서버** 의 역할을 하도록 한다.
         - `NodeMCU` 의 **IP**주소로 웹에서 접속하면 `NodeMCU` 서버가 `response` 한 값을 볼 수 있다.
3. ### [Mosquitto(ex63)](./Mosquitto/) & [MQTT(ex64_)](./MQTT/) 
   - 센서 디바이서에서 **정보**가 측정되면 해당 **정보**가 필요한 `client` 에게 전달 : `MQTT Broker`
     - 센서는 누가 해당 **정보** 를 필요로 하는지 알 필요가 없다.
   -   센서 = `Publisher` , 클라이언트 = `Subscriber` (보통은 이러한 관계를 갖지만 **둘다** 가능한 경우도 많다.)
       -   `Topic` 을 함께 보냄으로써 어떠한 **정보** 종류인지를 의미
   -  `Broker` 는 많은 종류의 **Topic** 과 **Value** 를 가진다.
   -  **Topic** 은 `Pub` 와 `Sub` 가 작동하는 기준이 된다.
      -  **/** 를 이용하여 계층적으로 구성
      -  **#** : 하위 토픽 `전체`
      -  **+** : `level` 한개 
   -  `QoS`  : `0`, `1`, `2` 단계로 나누어 제공
      -  `0` : 메시지 **한번** 전달, **Fire and Forget** (`NodeMCU` 에서 주로 쓴다.)
      -  `1` : 메시지 **여러번**, 핸드셰이킹 여부의 추적은 하되 **중복 여부** 는 되지 않음
      -  `2` : 메시지 **한번**, 핸드셰이킹 추적 **O** + 복원
   -  `MQTT Broker` 설치 : **_mosquitto_**
      -  **환경변수** 설정
      -  _mosquitto.conf_ 파일 수정 (하단에 **두줄** 추가)
         ```
         bind_address 0.0.0.0 : #Django 에서 allow address 한 것과 유사 
         allow_anonymous true : #계정을 체크하지 않겠다 !
         ```  
      - **방화벽** 설정
        - 외부 ▷ PC = `인바운드`
        - PC  ▷ 외부 = `아웃바운드`
        - 우리는 `nodeMCU` 가 `PC`로 들어오므로 **인바운드**
    - **Python** 으로 `Broker` 연동 : _**Paho**_
      - 이전에 사용한 `IoT` 가상환경 사용
      - `Subscribe`생성 → *[ex63_sub01.py](./Mosquitto/ex63_sub01.py)*
        - `loop_forever()` 와 `loop_start()` 
        - **daemon thread** 와 **main thread** 실습
    - `NodeMCU` 에서 `MQTT` 사용
      - *[ex64_nodeMCU_withMQTT](./MQTT/ex64_nodeMCU_withMQTT/)* : `NodeMCU` 에서 **Publish** 한 값을 `PC` 에서 **Subscribe** 하기
        - `PC`에서 **Publish** 도 함께 진행 
    - `MqttCom` 클래스를 만들어 **라이브러리**화
      - [libraries](../libraries/) 로 이동
      - *[ex65_nodeMCU_withMQTT_withClass](./MQTT/ex65_nodeMCU_withMQTT_withClass/)* : 클래스화 된 `MqttCom` 을 이용하여 **ex64** 구현
    - `DB` 와 연동준비를 위해 얻은 센서값 들을 **json** 으로 만들기
      - 관련 실습 : [ex66_json01.py](./Mosquitto/ex66_json01.py)