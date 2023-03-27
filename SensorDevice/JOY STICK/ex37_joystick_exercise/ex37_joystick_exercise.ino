const int x_joystick = A0;
const int y_joystick = A1;
const int z_sw = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(z_sw, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dx, dy;
  boolean sw;

  dx = analogRead(x_joystick);
  dy = analogRead(y_joystick);
  sw = digitalRead(z_sw);

  Serial.print("X-axis = ");
  Serial.println(dx);

  Serial.print("Y-axis = ");
  Serial.println(dy);

  Serial.print("Z-switch = ");
  if (sw == 0) Serial.println("0(ON)");
  else Serial.println("1(OFF)");

  delay(2000); 
}