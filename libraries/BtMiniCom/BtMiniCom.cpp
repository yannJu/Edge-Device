#include "BtMiniCom.h"

BtMiniCom::BtMiniCom(int rx, int tx, btminicom_callback_t callback = NULL, long serial_bps = 115200, int lcd_addr = 0x27) : MiniCom(serial_bps, lcd_addr), btSerial(rx, tx), callback(callback) {}

void BtMiniCom::init() {
  MiniCom::init();
  btSerial.begin(9600);
}

String BtMiniCom::readLine() {
  String message = "";

  while(btSerial.available()) {
    char data = (char)btSerial.read();

    message += data;
    delay(5);
  }

  message.trim();

  return message;
}

void BtMiniCom::send(String msg) {
  btSerial.println(msg);
}

void BtMiniCom::run() {
  String msg = readLine();

  if (msg != "" && callback != NULL) callback(msg);
  MiniCom::run();
}