import paho.mqtt.client as mqtt
from time import sleep

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    
    if rc == 0: 
        client.subscribe("iot/#") # 연결 성공시 토픽 구독
    else:
        print(f"Connect Failed. . .  [[{rc}]]")
        
def on_message(client, userdata, msg):
    value = float(msg.payload.decode())
    
    print(f" {msg.topic} {value} ")
    
# 1. MQTT 클라이언트 객체 인스턴스화
client = mqtt.Client()

# 2. 관련 이벤트에 대한 콜백함수 등록
client.on_connect = on_connect
client.on_message = on_message

try:
    # 3. 브로커 연결
    client.connect("localhost")
    client.loop_start()
    # client.loop_forever()
    
except Exception as e:
    print("Error - ! >> ", e)
    
# 메인스레드 동작  하면서 Subscribe 가 동시로 이루어짐
while True: 
    sleep(1) # 초 단위 : 1초
    print('-*-*-*-*-*-*-*-*-*-*-*-') # 메인스레드의 역할 : 1초 단위로 출력