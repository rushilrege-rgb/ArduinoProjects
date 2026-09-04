#include <Servo.h>


int xPin = A0;
int sPin = 2;
int xVal;
int sVal;

int servoPin = 9;
int servoPos;
Servo myServo;


int dt = 20;



void setup() {
  // put your setup code here, to run once:
  pinMode(xPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
  myServo.attach(servoPin);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  xVal = analogRead(xPin);
  sVal = digitalRead(sPin);

  servoPos = (90./513.)*xVal;

  myServo.write(servoPos);

  Serial.print(servoPos);
  Serial.print(" ");
  Serial.print(xVal);
  Serial.println("");

  delay(dt);

}
