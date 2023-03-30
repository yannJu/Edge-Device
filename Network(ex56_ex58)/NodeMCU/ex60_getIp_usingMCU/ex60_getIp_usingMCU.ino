#include <ESP8266WiFi.h>
#include <MiniCom.h>

const char *ssid = "TECHBREW_2G";
const char *pwd = "tech1234!";

MiniCom com;

void setup() {
  // put your setup code here, to run once:
  com.init();
  wifi_connect();
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void wifi_connect() {
  WiFi.begin(ssid, pwd);
  com.print(0, "Try to Connect-");

  Serial.println();
  
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(". ");
  }

  com.print(0, "WiFi Connected - !");
  com.print(1, "IP/" + WiFi.localIP().toString());

  Serial.println();
  Serial.println(WiFi.localIP());
}
