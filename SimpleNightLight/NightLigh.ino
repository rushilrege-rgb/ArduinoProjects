int readPin = A5;
int readVal;
int red = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(readPin);
  Serial.println(readVal);


  while(readVal < 300){
    digitalWrite(red, HIGH);
    readVal = analogRead(readPin);
  }

  digitalWrite(red, LOW);
}




