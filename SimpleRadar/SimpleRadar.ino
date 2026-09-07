#include <Servo.h>
#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myServo;
int servoPin = 3;
int servoPos;

int xPin = A5;
int xVal;

int echoPin = 5;
int trigPin = 4;
long duration;
float distance;


void pad(int col, int row, String text){
  while(text.length() < 16){
    text += " ";
  }
  lcd.setCursor(col, row);
  lcd.print(text);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  myServo.attach(servoPin);

  pinMode(xPin, INPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16,2);

  lcd.setCursor(0,0);
  lcd.print("Distance: ");

}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  servoPos = (90./513.)*xVal;
  myServo.write(servoPos);
  
  
  digitalWrite(trigPin, LOW);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration * 0.034)/2;

  Serial.println(distance);

  pad(0, 1, String(distance));
  pad(5, 1, "cm");

  
  delay(500);


}
