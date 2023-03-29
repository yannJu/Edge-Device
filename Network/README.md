## Network 관련 Exercise (ex56_) 📿
---
1. ### [Bluetooth(ex56_ex)](./Bluetooth/)
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
2. 