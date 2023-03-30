#include <WifiMiniCom.h>

const char *ssid = "TECHBREW_2G";
const char *pwd = "tech1234!";

WifiMiniCom wificom;

void setup() {
  // put your setup code here, to run once:
  wificom.init(ssid, pwd);
}

void loop() {
  // put your main code here, to run repeatedly:
  wificom.run();
}
