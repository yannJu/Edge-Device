#include <SoftwareSerial.h>
#include <MiniCom.h>

MiniCom com;
SoftwareSerial BTSerial(13, 12); 

String myString = "";
int count = 0;

void setup() {
  // put your setup code here, to run once:
  com.init();
  com.print(0, "[[BT Communicate]]");
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(BTSerial.available()) {
    char myChar = (char)BTSerial.read();

    myString += myChar;
    delay(5);
  }

  if (!myString.equals("")) {
    myString.trim();
    char buf[17];

    sprintf(buf, "%d)%s", ++count, myString.c_str());
    com.print(1, buf);
    BTSerial.println("input value : " + myString);
    myString = "";
  }
}
