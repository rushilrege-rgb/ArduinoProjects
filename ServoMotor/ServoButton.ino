#include <Servo.h>

int leftButton = 8;
int rightButton = 7;
int leftButtonVal;
int rightButtonVal;


Servo myServo;
int servoPin = 10;
int servoPos = 90;
int increment = 5;

int dt = 15;




void setup() {
  // put your setup code here, to run once:
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  
  myServo.attach(servoPin);
  myServo.write(servoPos);
  
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  leftButtonVal = digitalRead(leftButton);
  rightButtonVal = digitalRead(rightButton);

  if(leftButtonVal == 0){
    if(servoPos != 0){
      servoPos -= increment;
      myServo.write(servoPos);
    }
  }
  delay(dt);

  if(rightButtonVal == 0){
    if(servoPos != 180){
      servoPos += increment;
      myServo.write(servoPos);
    }
  }
  delay(dt);













  

}
