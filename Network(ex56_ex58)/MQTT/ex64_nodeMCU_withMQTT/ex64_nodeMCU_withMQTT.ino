#include <WifiMiniCom.h>
#include <PubSubClient.h>
#include <LED.h>

const char *ssid = "TECHBREW_2G";
const char *pwd = "tech1234!";

const char *mqtt_server = "172.30.1.98"; // mqtt broker ip

WifiMiniCom wificom;

WiFiClient espClient; // Client Socket 
PubSubClient client(espClient); // Client Handler

LED led(BUILTIN_LED); // nodeMCU LED -> D4 에 연결되어있음 (Subscribe 제어)

int value = 0; // Publish data

void setup() {
  // put your setup code here, to run once:
  wificom.init(ssid, pwd);
  wificom.setInterval(2000, publish);

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  wificom.run();
  if(!client.connected()) reconnect(); //client 가 연결될 때 까지 reconnect

  client.loop(); //client 가 연결되면 loop
}

void callback(char *topic, byte *payload, unsigned int length) { // Python 에서 on_message 와 같은 동작
  char buf[128];
  memcpy(buf, payload, length);
  buf[length] = '\0'; //Null 추가 = String 으로 만듦

  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]  ");
  Serial.println(buf);

  wificom.print(0, topic);
  wificom.print(1, buf);

  if (buf[0] == '1') led.setValue(LOW); // Pull up 방식이기 때문에 LOW
  else led.setValue(HIGH);
}

void reconnect() {
  while(!client.connected()) {
    Serial.print("Attemping MQTT Connection . . ");

    if (client.connect("ESP8266Client")) { // 원하는 Client 에 연결이 되었다면 + 아두이노에서는 이름을 주어야함! 랜덤 지정 없다 . .(랜덤하게 주는건 나중에) + 클라이언트 ID 중복 주의
      Serial.println("[[Connected!]]");

      client.publish("outTopic", "Im yanjo. . !");
      client.subscribe("inTopic"); // Subscribe 할 토픽 등록
    }
    else {
      Serial.print("Failed, rc = ");
      Serial.print(client.state());

      Serial.println("Try again in 5 Seconds. . ");
      delay(5000); // 5초 delay
    }
  }
}

void publish() {
  char msg[50];
  ++value;

  sprintf(msg, "Check Count . . . / %d /", value);
  Serial.print("Publish message : ");
  Serial.println(msg);

  client.publish("outTopic", msg); // outTopic 토픽에 msg 를 publish
}