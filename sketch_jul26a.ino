#include<Servo.h> //Servo 라이브러리를 추가
Servo servo;      //Servo 클래스로 servo객체 생성
int servo_Pin = 5;
int min_value = 544;
int max_value = 2400;

void setup() {
  Serial.begin(9600); 
  Serial.println("Servo value = ?");
  
  servo.attach(servo_Pin, min_value, max_value);
  servo.write(90);
}

void loop() {
  if(Serial.available() > 0){
    int servo_value = Serial.parseInt();

    servo.write(servo_value);
    Serial.println(servo_value);
    if(servo_value>=70){
      delay(2000); 
    }
  }
}
