#include <WifiMiniCom.h>

const char *ssid = "TECHBREW_2G";
const char *pwd = "tech1234!";

WifiMiniCom wificom;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  wificom.init(ssid, pwd);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();

  if (!client) return;

  Serial.println("New Client!");
  while (!client.available()) delay(1);

  String request = client.readStringUntil('\r');
  Serial.println(request);

  client.flush();

  //==========Respond

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("Im YanJo");
  client.println("</html>");

  delay(1);

  Serial.println("Client disconnected");
  Serial.println("");
}
