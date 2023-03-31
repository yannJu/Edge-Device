#include <ArduinoJson.h>
#include <MqttCom.h>

MqttCom com;
const char *ssid = "ㅇㅇㅈㅇ ㅇㅇㅍ";
const char *pwd = "2duswn!!";
const char *mqtt_server = "172.20.10.5";

void setup() {
  // put your setup code here, to run once:
  com.init(ssid, pwd);
  com.setServer(mqtt_server, "iot/yanjo/control", callback);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void callback(char *topic, byte *payload, unsigned int length) {
  StaticJsonDocument<256> doc;
  char buf[128];

  memcpy(buf, payload, length);
  buf[length] = '\0';

  auto error = deserializeJson(doc, buf);

  if (error) {
    Serial.print("deserializeJson() fauled with code ");
    Serial.println(error.c_str());
    return;
  }

  // const char* led = doc["led"];
  int led = doc["led"].as<int>();
  const char* door = doc["door"];
  // float value = doc["value"].as<float>();

  // Serial.println(led);
  // Serial.println(door);
  String result = "door is ";
  result += door;
  
  com.print(0, "led : ", led);
  com.print(1, result);
}
