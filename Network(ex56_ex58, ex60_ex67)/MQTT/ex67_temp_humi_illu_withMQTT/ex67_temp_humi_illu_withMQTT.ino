#include <MqttCom.h>
#include <DHT.h>
#include <Analog.h>

MqttCom com;

const char *ssid = "ㅇㅇㅈㅇ ㅇㅇㅍ";
const char *pwd = "2duswn!!";
const char *mqtt_server = "172.20.10.5";

int value = 0;

Analog cds(A0, 0, 100);
DHT dht11(D7, DHT11);

void setup() {
  // put your setup code here, to run once:
  com.init(ssid, pwd);
  com.setServer(mqtt_server);
  // com.setServer(mqtt_server, NULL, callback); //inTopic 으로 subscribe 도 함
  com.setInterval(3000, publish); //2초마다 publish

  dht11.begin();
}

void loop() {
  // put your main code here, to run repeatedly: 
  com.run();
}

void publish() {
  int illu = cds.read();
  float humi, temp;

  humi = dht11.readHumidity();
  temp = dht11.readTemperature();

  com.print(0, "T:", temp, " H:", humi);
  com.print(1, "I:", illu);

  //publish
  com.publish("iot/yanjo/sensor/livingroom/illuminate", illu);
  com.publish("iot/yanjo/sensor/bedroom/temperature", temp);
  com.publish("iot/yanjo/sensor/kitchen/humidity", humi);
}