#include <MiniCom.h>
#include <DHT.h>

MiniCom com;
DHT dht11(12, DHT11);

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.setInterval(2000, check); // 샘플 간격이 2초 이므로 2초 간격

  dht11.begin();

  com.print(0, "[[DHT11]]");
  com.print(0, "Preparing. . .");
}

void loop() {
  // put your main code here, to run repeatedly:
  com.run();
}

void check () {
  float fh, fc, ff; // 습도, 섭씨, 화씨

  fh = dht11.readHumidity();
  fc = dht11.readTemperature();
  ff = dht11.readTemperature(true);

  if (isnan(fh) || isnan(fc) || isnan(ff)) {
    com.print(1, "FAILED-!");
    return;
  }

  com.print(1, "T:", fc, "H:", fh);
}