#include "WifiMiniCom.h"

WifiMiniCom::WifiMiniCom(int serial_bps, int lcd_addr) : MiniCom(serial_bps, lcd_addr) {}

void WifiMiniCom::init(const char *ssid, const char *pwd) {
  MiniCom::init();

  WiFi.begin(ssid, pwd);
  print(0, "Try to CONNECT...");

  Serial.println();

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(". ");
  }

  print(0, "WiFi Connected !");
  print(1, WiFi.localIP().toString().c_str());

  Serial.println();
  Serial.println(WiFi.localIP());
}