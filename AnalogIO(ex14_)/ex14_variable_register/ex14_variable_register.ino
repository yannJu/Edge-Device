const int var_pin = A0; // 아날로그 핀 0번
int analog_val; // 아날로그 값 저장 변수

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int digital_val; // 디지털 값
  float inputCalcVal; // 입력 전압값 

  digital_val = analogRead(var_pin); // 아날로그 핀에서 값 입력받아 변환
  digital_val = map(digital_val, 0, 1023, 1023, 0); // 범위를 반대로 뒤집음
  
  inputCalcVal = (float)digital_val / 1023. * 5.0; // 전압값 계산 
  // 값 출력
  Serial.println("==========================");
  Serial.print("Input Voltage(0~5V) = ");
  Serial.println(inputCalcVal);
  
  Serial.print("Digital Voltage(0~1023) = ");
  Serial.println(digital_val);
  Serial.println("==========================");

  delay(2000);
}
