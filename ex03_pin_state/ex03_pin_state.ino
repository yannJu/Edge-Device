const int pu_led_pin = 3; //pull up pin
const int pd_led_pin = 4; //pull down pin

int state = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200); // 시리얼 속도를 맞춰주어야 함
  pinMode(pd_led_pin, OUTPUT);
  pinMode(pu_led_pin, OUTPUT);
}
                                                                                                                
void loop() 
{
  // put your main code here, to run repeatedly:
  // state = 1 :  
  // state = 0 :
  Serial.print("state value : ");
  Serial.println(state);

  digitalWrite(pd_led_pin, state);
  digitalWrite(pu_led_pin, state);

  state = !state; // 상태를 계속 바꾸어줌
  delay(1000);
}