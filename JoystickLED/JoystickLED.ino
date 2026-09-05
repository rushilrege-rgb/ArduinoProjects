int red1 = 3;
int red2 = 5;
int blue1 = 4;
int blue2 = 2;
int yellow1 = 7;
int yellow2 = 6;
int green1 = 8;
int green2 = 9;


int xPin = A0;
int yPin = A1;

int xVal;
int yVal;

int dt = 50;


void setup() {
  // put your setup code here, to run once:
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);


  Serial.print(xVal);
  Serial.print(" ");
  Serial.print(yVal);
  Serial.println("");
  
  if(xVal == 510 && yVal == 530){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
  }
  


  else if(xVal == 0 && yVal == 530){
    digitalWrite(blue2, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
  }

  else if(xVal == 1023 && yVal == 530){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, HIGH);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
  }

  else if(xVal == 510 && yVal == 0){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, HIGH);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
  }

  else if(xVal == 510 && yVal == 1023){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, HIGH);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
  }

  else if(xVal == 0 && yVal == 0){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
  }

  else if(xVal == 1023 && yVal == 0){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, HIGH);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
  }

  else if(xVal == 0 && yVal == 1023){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, HIGH);
  }

  else if(xVal == 1023 && yVal == 1023){
    digitalWrite(blue2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green1, HIGH);
    digitalWrite(green2, LOW);
  }
  





  



}
