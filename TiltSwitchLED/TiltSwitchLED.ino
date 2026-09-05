int tiltSwitch = 2;
int tiltVal;

int redLED = 8;
int greenLED = 9;



void setup() {
  // put your setup code here, to run once:
  pinMode(tiltSwitch, INPUT);
  digitalWrite(tiltSwitch, HIGH);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  tiltVal = digitalRead(tiltSwitch);
  Serial.println(tiltVal);
  delay(100);


  if(tiltVal == 0){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else{
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }

}
