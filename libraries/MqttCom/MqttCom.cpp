#include "MqttCom.h"

MqttCom::MqttCom(int serial_bps, int lcd_addr) : WifiMiniCom(serial_bps, lcd_addr), client(espClient) {
  topic = NULL;
  callback = NULL;
  server = NULL;

  // 랜덤하게 클라이언트 ID 배정
  randomSeed(analogRead(0));
  int r = random(300);

  client_id = String("ESP8266Client") + r;
}

void MqttCom::init(const char *ssid, const char *pwd, int no_lcd) {
  WifiMiniCom::init(ssid, pwd);
  if (no_lcd) WifiMiniCom::setNoLcd();
}

void MqttCom::setServer(const char *server, const char *topic, MQTT_CALLBACK_SIGNATURE) {
  this->server = server;
  this->topic = topic;
  this->callback = callback;

  client.setServer(server, 1883);
  if (callback != NULL) client.setCallback(callback);
}

void MqttCom::reconnect() {
  while (!client.connected()) {
    Serial.print("Attemping MQTT Connection. . .");
    print(0, "Try MQTT Con . . ");

    if (client.connect(client_id.c_str())) {
      Serial.println("Connected! --");
      print(0, "MQTT Connected!");

      if (topic != NULL) client.subscribe(topic); // topic 이 들어오면 client 는 subscribe 도 받음
    }
    else {
      char buf[17];
      sprintf(buf, "FAILED, rc = %d", client.state());
      Serial.print(buf);
      print(0, buf);

      Serial.println(" Try again in 5 Sec. .");
      print(1, "Try again in 5s -");

      delay(5000);
    }
  }
}

void MqttCom::run() {
  MiniCom::run();

  if (!client.connected()) reconnect();
  client.loop();
}

void MqttCom::publish(const char *topic, const char *value) {client.publish(topic, value);}

void MqttCom::publish(const char *topic, int value) {
  char msg[10];
  sprintf(msg, "%d", msg);
  client.publish(topic, msg);
}

void MqttCom::publish(const char *topic, float value) {
  String msg = "";
  msg += value;
  client.publish(topic, msg.c_str());
}