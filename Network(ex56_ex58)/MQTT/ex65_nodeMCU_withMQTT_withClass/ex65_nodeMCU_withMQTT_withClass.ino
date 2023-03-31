#include "MqttCom.h"
#include <LED.h>

LED led(BUILTIN_LED);

MqttCom com;

const char *ssid = "TECHBREW_2G";
const char *pwd = "tech1234!";
const char *mqtt_server = "172.30.1.98";

int value = 0;

void setup() {
  // put your setup code here, to run once:
  com.init(ssid, pwd);
  com.setServer(mqtt_server, "inTopic", callback); //inTopic 으로 subscribe 도 함
  com.setInterval(2000, publish); //2초마다 publish
}

void loop() {
  // put your main code here, to run repeatedly: 
  com.run();
}

void callback(char *topic, byte *payload, unsigned int length) {
  char buf[128];

  memcpy(buf, payload, length);
  buf[length] = '\0'; 

  com.print(0, topic);
  com.print(1, buf);

  if (buf[0] == '1') led.setValue(LOW);
  else led.setValue(HIGH);
}

void publish() {
  char msg[50];
  
  ++value;
  sprintf(msg, "outTopic check Count / %d /", value);
  com.publish("outTopic", msg);
}